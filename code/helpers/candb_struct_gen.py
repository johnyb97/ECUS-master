#!/usr/bin/env python3

import traceback
import argparse

from enum import Enum
from collections import OrderedDict

parser = argparse.ArgumentParser(description='Convert canDB jsonfile to C structure')

parser.add_argument('input_file', metavar='input_file', type=str,
					help='json file exported from candb')

parser.add_argument('output_file', metavar='output_file', type=str,
					help='output file name, without extensions (c and h will be generated)')

args = parser.parse_args()

def validate_not_empty(src, fallback):
	if(src==None):
		return fallback
	elif(isinstance(src, str) and not src):
		return fallback
	else:
		return src

class Generator:
	def generate(self, indent=0):
		print("not implemented for class", self.__class__.__name__)
		return "//not implemented for class"+ self.__class__.__name__

class Custom_enum_element:
	def __init__(self, name, value=None, description_text=None):
		self.name=name
		self.value=value
		self.description_text=description_text



class Custom_enum(Generator):
	def __init__(self, name):
		# print("NEW ENUM "+name)
		self.name = name
		self.enum = OrderedDict()
		self.type = "candb_enum_{}_t".format(self.name)
	
	def append(self, element):
		if(not isinstance(element, Custom_enum_element)):
			raise Exception("Enum element is not instance of Custom_enum_element, but: {}".format(type(element)))
		if(validate_not_empty(element.name, None) == None):
			print("\tempty enum key, ignoring")
			return
		if(element.name in self.enum):
			print("\tENUM DUMP:")
			for k in self.enum:
				print(k, "=", self.enum[k])
			raise Exception("Enum already has value called: {}".format(element.name))

		if(element.value==None):
			if(len(self.enum)==0):#if empty
				element.value = 0#start with zero
			else:	
				element.value = self.enum[next(reversed(self.enum))].value+1 #othwerwise take previous value and add 1
		self.enum[element.name] = element
	
	def generate(self, indent=0):
		if(len(self.enum)==0):
			return ""
		ind="\n"+"\t"*indent
		buffer=""
		buffer+=ind+"typedef enum{"
		for k in self.enum:
			buffer+=ind+"\tCANDB_{}_{}={}, //{}".format(self.name.upper(), k.upper(), self.enum[k].value, validate_not_empty(self.enum[k].description_text, "description not provided"))
		buffer+=ind+"}"+self.type+";"
		return buffer
	
	def generate_descriptions(self, indent=0):
		if(len(self.enum)==0):
			return ""
		ind="\n"+"\t"*indent
		buffer=""
		buffer+=ind+"const candb_descrition_map_t *const {}_descriptions[]={{".format(self.name)
		for k in self.enum:
			buffer+=ind+"\t(const candb_descrition_map_t[]){{{{ CANDB_{}_{}, \"{}\" }}}},".format(self.name.upper(), k.upper(), self.enum[k].description_text)
		buffer+=ind+"NULL}};".format()
		return buffer
	



class Description(Generator):
	def __init__(self, name, comments):
		if(not isinstance(comments, list)):
			raise Exception("Description comments must be instance of list")
		self.name = name
		self.comments = []
		for c in comments:
			tmp=c.replace("\n","").replace("\r","")
			if(tmp):
				self.comments.append(tmp)
	
	def __str__(self):
		buffer=self.name
		for c in self.comments:
			buffer += " | "+c
		return buffer

	
	def generate(self, indent=0):
		buffer=""
		buffer+="{.name=\""+validate_not_empty(self.name, "Invalid")+"\", .comments=\"{}\"}}".format(' '.join(self.comments))
		return buffer

class Candb_enum_element(Generator):
	def __init__(self, value, description):
		if(not isinstance(description, Description)):
			raise Exception("description must be instance of class Description")
		self.value = int(value)
		self.description = description

class Candb_enum(Generator):
	def __init__(self):
		self.enum_elements=[]

	def add(self, element):
		if(not isinstance(element, Candb_enum_element)):
			raise Exception("elements must be instance of class Enum_element")
		self.enum_elements.append(element)


class Candb_msg_field_type(Enum):
	BOOL=0
	UINT=1
	INT=2
	FLOAT=3
	ENUM=4
	MUX=5

	def __str__(self):
		return 'CANDB_MSG_FIELD_TYPE_{0}'.format(self.name)
	
	@classmethod
	def generate(cls, indent=0):
		ind="\n"+"\t"*indent
		buffer=""
		buffer+=ind+"typedef enum{"
		for c in cls:
			buffer+=ind+"\t{},".format(c)
		buffer+=ind+"} candb_msg_field_type_t;"
		return buffer
		


	@staticmethod
	def from_str(s):
		if("uint" in s):
			return Candb_msg_field_type.UINT
		elif("int" in s):
			return Candb_msg_field_type.INT
		elif("bool" in s):
			return Candb_msg_field_type.BOOL
		elif("multiplex" in s):
			return Candb_msg_field_type.MUX
		elif("enum" in s):
			return Candb_msg_field_type.ENUM
		elif("float" in s):
			return Candb_msg_field_type.FLOAT
		else:
			raise Exception("Unknown field type: "+s)

class Candb_msg_field(Generator):
	def __init__(self, description, field_type, count, bits, pos_offset, unit, vmin=0, vmax=0, voffset=0, vfactor=1):
		if(not isinstance(description, Description)):
			raise Exception("description must be instance of class Description, is:", type(description))
		self.description = description
		self.field_type = Candb_msg_field_type.from_str(field_type)
		self.enum_descriptions_name = None if(self.field_type != Candb_msg_field_type.ENUM) else field_type.replace("enum ","")
		self.field_type_raw = field_type
		self.bits = bits
		self.pos_offset = pos_offset
		self.count = count
		self.unit = unit if(unit!=None) else "?"		
		self.vmin = validate_not_empty(vmin, " +0")
		self.vmax = validate_not_empty(vmax, " +0")
		self.voffset = validate_not_empty(voffset, " +0")
		self.vfactor = validate_not_empty(vfactor, " +1")
	
	def generate(self, indent=0):
		ind="\n"+"\t"*indent
		buffer=ind+"\t(const candb_msg_field_t []){{"
		buffer+=ind+"\t.description={},".format(self.description.generate(indent+1))
		buffer+=ind+"\t.type={},".format(str(self.field_type))
		buffer+=ind+"\t.unit=\"{}\",".format(str(self.unit))
		buffer+=ind+"\t.bits={},".format(self.bits)
		buffer+=ind+"\t.offset={},".format(self.pos_offset)
		buffer+=ind+"\t.count={},".format(self.count)
		buffer+=ind+"\t.timestamp=(uint32_t []){0},"
		
		if(self.field_type in [Candb_msg_field_type.INT, Candb_msg_field_type.UINT, Candb_msg_field_type.FLOAT]):
			buffer+=ind+"\t.type_specific.num={"
			buffer+=ind+"\t\t.min={},".format(self.vmin)
			buffer+=ind+"\t\t.max={},".format(self.vmax)
			buffer+=ind+"\t\t.factor={},".format(self.vfactor)
			buffer+=ind+"\t\t.offset={},".format(self.voffset)
			
			buffer+=ind+"\t\t.value=(raw32_t []){"

			tmp="{."
			if(self.field_type == Candb_msg_field_type.UINT):
				tmp+="ui"
			if(self.field_type == Candb_msg_field_type.INT):
				tmp+="si"
			if(self.field_type == Candb_msg_field_type.FLOAT):
				tmp+="fl"
			tmp+="=0}, "
			buffer+=""+"{}".format(tmp)*self.count+"},"
			buffer+=ind+"\t},"
			buffer+=ind+"}},"
		elif(self.field_type == Candb_msg_field_type.BOOL):
			buffer+=ind+"\t.type_specific.bl={"
			buffer+=ind+"\t\t.value=(bool []){"

			buffer+="false, "*self.count+"},"
			buffer+=ind+"\t},"
			buffer+=ind+"}},"
		elif(self.field_type == Candb_msg_field_type.ENUM):
			buffer+=ind+"\t.type_specific.en={"
			buffer+=ind+"\t\t.value=(uint16_t []){0},"
			buffer+=ind+"\t\t.descriptions={}_descriptions,".format(self.enum_descriptions_name)
			buffer+=ind+"\t},"
			buffer+=ind+"}},"
		elif(self.field_type == Candb_msg_field_type.MUX):
			buffer+=ind+"\t.type_specific.mux={"
			buffer+=ind+"\t\t.min={},".format(self.vmin)
			buffer+=ind+"\t\t.max={},".format(self.vmax)
			buffer+=ind+"\t\t.value=(uint8_t []){0},"
			buffer+=ind+"\t\t.muxed_fields=(const candb_msg_field_t *const *const[{}]){{".format(int(self.vmax)-int(self.vmin))
		else:
			buffer+=ind+"\t//field of type {} is not yet supported!".format(self.field_type.name)
			print("field of type {} is not yet supported!".format(self.field_type.name))
			buffer+=ind+"}},"

		
		return buffer
	
	def __str__(self):
		return "{:5} ({:2}:{:2}) [{}] {}".format(self.field_type.name, self.pos_offset+self.bits, self.pos_offset, self.bits, self.description)
			
class Candb_msg(Generator):
	def __init__(self, description, sent_by, identifier, length, timeout=0, period=0):
		if(not isinstance(description, Description)):
			raise Exception("description must be instance of class Description")
		self.description = description
		self.sent_by = sent_by
		try:
			self.identifier = int(identifier)
		except:
			raise Exception("In message: {}, from: {}, ID not number: {}".format(self.description.name, sent_by, identifier))
		self.length = int(length)
		self.timeout = timeout if(timeout!=None) else 0
		self.period = period if(period!=None) else 0
		self.fields = []
	
	def add_field(self, field):
		if(not isinstance(field, Candb_msg_field)):
			raise Exception("field be instance of class candb_msg_field")
		self.fields.append(field)

	def generate(self, indent=0):
		muxlevel=0
		ind="\n"+"\t"*indent
		buffer=""

		buffer+=ind+"(candb_msg_t []){{"
		buffer+=ind+".callback=(candb_msg_callback_p[]){NULL},"
		buffer+=ind+".timestamp=(uint32_t []){0},"
		buffer+=ind+".description={},".format(self.description.generate(indent+1))
		buffer+=ind+".sent_by=\"{}\",".format( ' '.join(self.sent_by) )
		buffer+=ind+".id={},".format(self.identifier)
		buffer+=ind+".length={},".format(self.length)
		buffer+=ind+".timeout={},".format(self.timeout)
		buffer+=ind+".period={},".format(self.period)
		buffer+=ind+".fields=(const candb_msg_field_t *const[]){"

		#now, let's take care of possible mux recursivity
		recbuff=[[0,""]]
		for f in self.fields:
			recbuff[-1][1]+= f.generate(indent+1+muxlevel)
			if(f.field_type == Candb_msg_field_type.MUX):
				muxlevel+=1
				recbuff.append([int(f.vmax)-int(f.vmin), ""])#save how large is MUX and prepare empty buffer for new level
		
		#assemble struxture level by level
		while (muxlevel):
			muxind = "\n"+"\t"*(muxlevel+1+indent)
			muxed_messages= muxind+"(const candb_msg_field_t *const[]){"
			muxed_messages+= recbuff[-1][1]
			muxed_messages+= muxind+"NULL},//end of muxed group array"

			recbuff[-2][1]+= recbuff[-1][0]*muxed_messages#duplicate this level MUX times
			recbuff.pop(-1)#throw away last buffer, it was merged to lower one
			recbuff[-1][1]+= muxind+"} //end of muxed groups array"#no NULL because array has known size
			recbuff[-1][1]+= muxind+"},//end of mux field init"
			recbuff[-1][1]+= muxind+"}},//end of MUX field struct"
			muxlevel-=1

		buffer+=recbuff[-1][1]
		buffer+=ind+"NULL}//end of fields array"
		buffer+=ind+"}},//end of message struct"
		return buffer
	
	def __str__(self):
		return "{} {} {}".format(self.sent_by, self.description.name, self.identifier)

parsed_messages=[]

parsed_enums=[]

indexing_enums=[]

message_enum= Custom_enum("msg")

import json

j = json.load(open(args.input_file))

for unit in j: #iterate over units (owners of messages)	
	msg_owner = unit.get("name")

	for j_enum in unit.get("enum_types"): #parse enums
		enum=Custom_enum("{}_{}".format(msg_owner, j_enum.get("name")))
		for item in j_enum.get("items"):
			enum.append(Custom_enum_element( "{}_{}".format(msg_owner, item.get("name")), item.get("value"), item.get("description")))
		parsed_enums.append(enum)

	for msg in unit.get("messages"):
		# print(msg)
		try:
			m = Candb_msg(	description=Description(msg.get("name"), comments=msg.get("comments")),
							sent_by=msg.get("sentBy"), 
							identifier=msg.get("id"),
							length=msg.get("length"),
							timeout=msg.get("timeout"),
							period=msg.get("period"))
			print("message: ",m)
		except Exception as e:
			print("\tInvalid message, ",e)
			#traceback.print_exc()
			continue
		
		if(len(m.sent_by)==0):
			print("\tmessage ignored, nobody sends it...")
			continue
		
		parsed_messages.append(m)
		message_enum.append(Custom_enum_element( "{}_{}".format(msg_owner, m.description.name), description_text="{} ".format(msg_owner)+' '.join(m.description.comments) ))
		
		field_enum=Custom_enum(msg_owner+"_"+m.description.name+"_FIELD")
		for field in msg.get("fields"):
			try:
				name = field.get("name")
				if(len(name)>0):
					f = Candb_msg_field(	description=Description(field.get("name"), comments=field.get("comments")),
											field_type=field.get("type"),
											count=field.get("count"),
											bits=field.get("bits"),
											pos_offset=field.get("start_bit"),
											unit=field.get("unit"),
											vmin=field.get("min"),
											vmax=field.get("max"),
											voffset=field.get("offset"),
											vfactor=field.get("factor"))
					# print("adding field: ",f)
					m.add_field(f)
					field_enum.append(Custom_enum_element(f.description.name, description_text=' '.join(f.description.comments) ))
				else:
					print("\tnoname field, ignored!")	
			except Exception as e:
				print("\terror parsing field!", e)
			
		indexing_enums.append(field_enum)

indexing_enums.append(message_enum)

hfile_contents=["""//by xorly

#ifndef _CANDB_STRUCTURE
	#define _CANDB_STRUCTURE
	#include <inttypes.h>
	#include <stdbool.h>

	typedef struct{
		const uint8_t id;
		const char *const text;
	}candb_descrition_map_t;

	typedef struct{
		const char *const name;
		const char *const comments;
	}description_t;

	typedef struct{
		const uint16_t value;
		const description_t description;
	}enum_element_t;

	typedef struct{
		const enum_element_t *const element;
	}enum_t;

	typedef union{
		uint32_t ui;
		int32_t si;
		float fl;
	}raw32_t ;
""",
Candb_msg_field_type.generate(1),
"""

	struct candb_msg_field{
		const description_t description;
		const candb_msg_field_type_t type;
		const char *unit;
		const uint8_t bits;
		const uint8_t offset;
		const uint8_t count;
		uint32_t *const timestamp;
		const union{
			struct{
				const float min;
				const float max;
				const float factor;
				const float offset;
				raw32_t *const value;
			}num;
			struct{
				bool *const value;
			}bl;
			struct{
				const candb_descrition_map_t *const *const descriptions;
				uint16_t *const value;
			}en;
			struct{
				const struct candb_msg_field *const *const *const muxed_fields;
				const uint8_t min;
				const uint8_t max;
				uint8_t *const value;
			}mux;
		}type_specific;
	};

	typedef struct candb_msg_field candb_msg_field_t;

	struct candb_msg{
		uint32_t *const timestamp;
		const char *const sent_by;
		const candb_msg_field_t *const *const fields;
		void (**callback)(const struct candb_msg *msg);
		const description_t description;
		const uint16_t id;
		const uint16_t timeout;
		const uint16_t period;
		const uint8_t length;
	};

	typedef struct candb_msg candb_msg_t;
	typedef void(*candb_msg_callback_p)(const struct candb_msg *msg);

	extern const candb_msg_t  *const *const candb_messages;
"""]
for e in indexing_enums:
	hfile_contents.append(e.generate(1))

for e in parsed_enums:
	hfile_contents.append(e.generate(1))

hfile_contents.append("\n#endif\n")

print("generating...")

hfile = open(args.output_file+".h", "w")
hfile.writelines(hfile_contents)
hfile.close()


cfile_contents = ["""//by xorly

#include \""""+args.output_file+""".h\"

#ifndef NULL
	#define NULL ( (void *) 0)
#endif

"""]

for e in parsed_enums:
	cfile_contents.append(e.generate_descriptions())

cfile_contents.append("\nconst candb_msg_t  *const *const candb_messages=(const candb_msg_t *const []){\n")
for m in parsed_messages:
	cfile_contents.append(m.generate(1))
cfile_contents.append("\nNULL};\n")

cfile_contents.append("\n//and that is the END!\n")

cfile = open(args.output_file+".c", "w")
cfile.writelines(cfile_contents)
cfile.close()
