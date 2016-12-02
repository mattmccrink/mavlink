#!/usr/bin/env python
'''
parse a MAVLink protocol XML file and generate a CSharp implementation


'''
from __future__ import print_function

from builtins import range
import sys, textwrap, os, time, platform
from . import mavparse, mavtemplate

t = mavtemplate.MAVTemplate()

# todo - refactor this in to the other array
map = {
        'float'    : 'float',
        'double'   : 'double',
        'char'     : 'byte',
        'int8_t'   : 'sbyte',
        'uint8_t'  : 'byte',
        'uint8_t_mavlink_version'  : 'B',
        'int16_t'  : 'Int16',
        'uint16_t' : 'UInt16',
        'int32_t'  : 'Int32',
        'uint32_t' : 'UInt32',
        'int64_t'  : 'Int64',
        'uint64_t' : 'UInt64',
        }

# Map of field type to bitconverter bytedecoding function, and number of bytes used for the encoding
mapType = {
        'float'    : ('ToSingle', 4),
        'double'   : ('ToDouble', 8),
        'int8_t'   : ('ToInt8', 1),
        'uint8_t'   : ('ToUInt8', 1),
        'char'   :   ('ToChar', 1),
        'int16_t'  : ('ToInt16', 2),
        'uint16_t' : ('ToUInt16', 2),
        'int32_t'  : ('ToInt32', 4),
        'uint32_t' : ('ToUInt32', 4),
        'int64_t'  : ('ToInt64', 8),
        'uint64_t' : ('ToUInt64', 8),
        }        

# Map of field names to names that are C# compatible and not illegal class field names
mapFieldName = {
        'fixed'    : '@fixed'
        }                
        
def generate_preamble(outf, msgs, args, xml):
    print("Generating preamble")
    t.write(outf, """
/*
MAVLink protocol implementation (auto-generated by mavgen.py)

Generated from: ${FILELIST}

Note: this file has been auto-generated. DO NOT EDIT
*/

using System;
""", {'FILELIST' : ",".join(args)})

def generate_xmlDocSummary(outf, summaryText, tabDepth):
    indent = '\t' * tabDepth
    escapedText = summaryText.replace("\n","\n%s///" % indent)
    outf.write("\n%s/// <summary>\n" % indent)
    outf.write("%s/// %s\n" % (indent, escapedText))
    outf.write("%s/// </summary>\n" % indent)
    
    
def generate_enums(outf, enums):
    print("Generating enums")
    outf.write("namespace MavLink\n{\n")
    for e in enums:
            #if len(e.description) > 0:
        generate_xmlDocSummary(outf, e.description, 1)
        outf.write("\tpublic enum %s : uint\n\t{\n" % e.name)

        for entry in e.entry:
            if len(entry.description) > 0:
                generate_xmlDocSummary(outf, entry.description, 2)
            outf.write("\t\t%s = %u,\n" % (entry.name, entry.value))

        outf.write("\n\t}\n\n")
    outf.write("\n}\n")
        
def generate_classes(outf, msgs):
    print("Generating class definitions")

    outf.write("""
    
   
namespace MavLink\n{

    public abstract class MavlinkMessage
    {
        public abstract int Serialize(byte[] bytes, ref int offset);
    }
""")

    for m in msgs:
        if (len(m.description) >0):
            generate_xmlDocSummary(outf, m.description, 1)
        outf.write("""\tpublic class Msg_%s : MavlinkMessage
    {
""" % m.name.lower())
    
        for f in m.fields:
            if (f.description.upper() != f.name.upper()):
                generate_xmlDocSummary(outf, f.description, 2)
            if (f.array_length):
                outf.write("\t\tpublic %s[] %s; // Array size %s\n" % (map[f.type], mapFieldName.get(f.name, f.name), f.array_length))
            else:
                outf.write("\t\tpublic %s %s;\n" % (map[f.type], mapFieldName.get(f.name, f.name)))
        
        outf.write("""
        public override int Serialize(byte[] bytes, ref int offset)
            {
                return MavLinkSerializer.Serialize_%s(this, bytes, ref offset);
            }        
""" % m.name.upper())

        outf.write("\t}\n\n")    
    outf.write("}\n\n")

    
   
def generate_Deserialization(outf, messages):
    
    # Create the deserialization funcs 
    for m in messages:
        classname="Msg_%s" % m.name.lower()
        outf.write("\n\t\tinternal static MavlinkMessage Deserialize_%s(byte[] bytes, int offset)\n\t\t{\n" % (m.name))
        offset = 0
    
        outf.write("\t\t\treturn new %s\n" % classname)
        outf.write("\t\t\t{\n")

        for f in m.ordered_fields:
            if (f.array_length):
                outf.write("\t\t\t\t%s =  ByteArrayUtil.%s(bytes, offset + %s, %s),\n" % (mapFieldName.get(f.name, f.name), mapType[f.type][0], offset, f.array_length))
                offset += (f.array_length * mapType[f.type][1])
                continue
          
            # mapping 'char' to byte here since there is no real equivalent in the CLR
            if (f.type == 'uint8_t' or f.type == 'char' ):
                    outf.write("\t\t\t\t%s = bytes[offset + %s],\n" % (mapFieldName.get(f.name, f.name),offset))
                    offset+=1          
            else:             
                outf.write("\t\t\t\t%s = bitconverter.%s(bytes, offset + %s),\n" % (mapFieldName.get(f.name, f.name), mapType[f.type][0] ,  offset))
                offset += mapType[f.type][1]

        outf.write("\t\t\t};\n")
        outf.write("\t\t}\n") 

    
def generate_Serialization(outf, messages):
    
    # Create the table of serialization delegates
    for m in messages:
        classname="Msg_%s" % m.name.lower()

        outf.write("\n\t\tinternal static int Serialize_%s(this %s msg, byte[] bytes, ref int offset)\n\t\t{\n" % (m.name, classname))
        offset=0
        
        # Now (since Mavlink 1.0) we need to deal with ordering of fields
        for f in m.ordered_fields:
        
            if (f.array_length):
                outf.write("\t\t\tByteArrayUtil.ToByteArray(msg.%s, bytes, offset + %s, %s);\n" % (f.name, offset, f.array_length))
                offset += f.array_length * mapType[f.type][1]
                continue

            if (f.type == 'uint8_t'):
                outf.write("\t\t\tbytes[offset + %s] = msg.%s;\n" % (offset,mapFieldName.get(f.name, f.name)))
                offset+=1
            elif (f.type == 'int8_t'):
                outf.write("\t\t\tbytes[offset + %s] = unchecked((byte)msg.%s);\n" % (offset,mapFieldName.get(f.name, f.name)))
                offset+=1
            elif (f.type == 'char'):
                outf.write("\t\t\tbytes[offset + %s] = msg.%s; // todo: check int8_t and char are compatible\n" % (offset,mapFieldName.get(f.name, f.name)))
                offset+=1
            else:
                outf.write("\t\t\tbitconverter.GetBytes(msg.%s, bytes, offset + %s);\n" % (mapFieldName.get(f.name, f.name),offset))
                offset += mapType[f.type][1]
          
        outf.write("\t\t\toffset += %s;\n" % offset)
        outf.write("\t\t\treturn %s;\n" % m.id)
        outf.write("\t\t}\n") 


def generate_CodecIndex(outf, messages, xml):
    
    outf.write("""

/*
MAVLink protocol implementation (auto-generated by mavgen.py)

Note: this file has been auto-generated. DO NOT EDIT
*/

using System;
using System.Collections;
using System.Collections.Generic;
    
namespace MavLink
{
    public static class MavlinkSettings
    {
""")
    outf.write('\t\tpublic const string WireProtocolVersion = "%s";' % xml[0].wire_protocol_version)
    outf.write('\n\t\tpublic const byte ProtocolMarker = 0x%x;' % xml[0].protocol_marker)
    outf.write('\n\t\tpublic const bool CrcExtra = %s;' % str(xml[0].crc_extra).lower())
    outf.write('\n\t\tpublic const bool IsLittleEndian = %s;' % str(xml[0].little_endian).lower())
    
    outf.write("""
    }
    
    public delegate MavlinkMessage MavlinkPacketDeserializeFunc(byte[] bytes, int offset);

    //returns the message ID, offset is advanced by the number of bytes used to serialize
    public delegate int MavlinkPacketSerializeFunc(byte[] bytes, ref int offset, object mavlinkPacket);
 
    public class MavPacketInfo
    {
        public MavlinkPacketDeserializeFunc Deserializer;
        public int [] OrderMap;
        public byte CrcExtra;

         public MavPacketInfo(MavlinkPacketDeserializeFunc deserializer, byte crcExtra)
         {
             this.Deserializer = deserializer;
             this.CrcExtra = crcExtra;
         }
    }
 
    public static class MavLinkSerializer
    {
        public static void SetDataIsLittleEndian(bool isLittle)
        {
            bitconverter.SetDataIsLittleEndian(isLittle);
        }
    
        private static readonly FrameworkBitConverter bitconverter = new FrameworkBitConverter(); 
    
        public static Dictionary<int, MavPacketInfo> Lookup = new Dictionary<int, MavPacketInfo>
        {""")

    for m in messages:
        classname="Msg_%s" % m.name.lower()
        outf.write("\n\t\t\t{%s, new MavPacketInfo(Deserialize_%s, %s)}," % (m.id, m.name, m.crc_extra))
    outf.write("\n\t\t};\n")
   

def generate(basename, xml):
    '''generate complete MAVLink CSharp implemenation'''
    structsfilename = basename + '.generated.cs'
   
    msgs = []
    enums = []
    filelist = []
    for x in xml:
        msgs.extend(x.message)
        enums.extend(x.enum)
        filelist.append(os.path.basename(x.filename))

    for m in msgs:
        m.order_map = [ 0 ] * len(m.fieldnames)
        for i in range(0, len(m.fieldnames)):
            m.order_map[i] = m.ordered_fieldnames.index(m.fieldnames[i])
        
        m.fields_in_order = []
        for i in range(0, len(m.fieldnames)):
            m.order_map[i] = m.ordered_fieldnames.index(m.fieldnames[i])
        
    print("Generating messages file: %s" % structsfilename)
    dir = os.path.dirname(structsfilename)
    if not os.path.exists(dir):
        os.makedirs(dir)
    outf = open(structsfilename, "w")
    generate_preamble(outf, msgs, filelist, xml[0])
    
    outf.write("""
    
using System.Reflection;    
    
[assembly: AssemblyTitle("Mavlink Classes")]
[assembly: AssemblyDescription("Generated Message Classes for Mavlink. See http://qgroundcontrol.org/mavlink/start")]
[assembly: AssemblyProduct("Mavlink")]
[assembly: AssemblyVersion("1.0.0.0")]
[assembly: AssemblyFileVersion("1.0.0.0")]

    """)
    
    generate_enums(outf, enums)
    generate_classes(outf, msgs)
    outf.close()
    
    print("Generating the (De)Serializer classes")
    serfilename = basename + '_codec.generated.cs'
    outf = open(serfilename, "w")
    generate_CodecIndex(outf, msgs, xml)
    generate_Deserialization(outf, msgs)
    generate_Serialization(outf, msgs)
    
    outf.write("\t}\n\n")
    outf.write("}\n\n")
    
    outf.close()
    
    # Some build commands depend on the platform - eg MS .NET Windows Vs Mono on Linux
    if platform.system() == "Windows":
        winpath=os.environ['WinDir']
        cscCommand = winpath + "\\Microsoft.NET\\Framework\\v4.0.30319\\csc.exe"
        
        if (os.path.exists(cscCommand)==False):
            print("\nError: CS compiler not found. .Net Assembly generation skipped")
            return   
    else:
        print("Error:.Net Assembly generation not yet supported on non Windows platforms")
        return
        cscCommand = "csc"

    print("Compiling Assembly for .Net Framework 4.0")
    
    generatedCsFiles = [ serfilename, structsfilename]
    
    includedCsFiles =  [ 'CS/common/ByteArrayUtil.cs', 'CS/common/FrameworkBitConverter.cs', 'CS/common/Mavlink.cs'  ]
    
    outputLibraryPath = os.path.normpath(dir + "/mavlink.dll")
    
    compileCommand = "%s %s" % (cscCommand, "/target:library /debug /out:" + outputLibraryPath)
    compileCommand = compileCommand + " /doc:" + os.path.normpath(dir + "/mavlink.xml")  
    
    for csFile in generatedCsFiles + includedCsFiles:
        compileCommand = compileCommand + " " + os.path.normpath(csFile)
    
    #print("Cmd:" + compileCommand)
    res = os.system (compileCommand)
    
    if res == '0':
        print("Generated %s OK" % filename)
    else:
        print("Error")
