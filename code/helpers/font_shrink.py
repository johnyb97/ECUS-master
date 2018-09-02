#!/bin/env python3

import argparse

parser = argparse.ArgumentParser(description='Minimize font from LCD Image Converter')

parser.add_argument('input_font_file', type=str,
					help='source file')

parser.add_argument('--header', action='store_true',
					help='generate header file font_types.h with typedefs')

args = parser.parse_args()


raw = open(args.input_font_file, "rt")

characters = []
font_name = "unknown"
ascii_offset = None

class CharacterBitmap:
	def __init__(self, char_num, raw_bitmap, width, height):
		self.char_num = char_num
		self.raw_bitmap = raw_bitmap
		self.raw_height = height
		self.raw_width = width
	
		# minimalization
		self.padding_left = self.raw_width
		self.padding_right = 0
		self.padding_top = self.raw_height
		self.padding_bottom = 0
		self.height = 0
		self.width = 0

		# left boundary
		for H_offset in range(self.raw_width):
			col = self.raw_bitmap[H_offset:len(self.raw_bitmap):self.raw_width]
			if any(col):
				self.padding_left = H_offset
				break

		# right boundary
		for H_offset in reversed(range(self.raw_width)):
			col = self.raw_bitmap[H_offset:len(self.raw_bitmap):self.raw_width]
			if any(col):
				self.padding_right = self.raw_width - H_offset - 1
				break

		# top boundary
		for V_offset in range(self.raw_height):
			row = self.raw_bitmap[V_offset*self.raw_width:(V_offset+1)*self.raw_width]
			if any(row):
				self.padding_top = V_offset
				break
		
		# bottom boundary
		for V_offset in reversed(range(self.raw_height)):
			row = self.raw_bitmap[V_offset*self.raw_width:(V_offset+1)*self.raw_width]
			if any(row):
				self.padding_top = self.raw_height - V_offset - 1
				break

	
		self.width = self.raw_width - self.padding_left - self.padding_right
		self.height = self.raw_height - self.padding_top - self.padding_bottom

		# print(self.padding_left, self.padding_right)
		# print(self.padding_top, self.padding_bottom)
		# print(self.width, self.height)
		before = self.raw_width*self.raw_height
		after = self.width*self.height
		print("{}, reduced size size {:6.2f} %".format(chr(self.char_num), after/before*100))
	
	def export(self, indent=0):
		ind = "\n"+"\t"*indent
		buff = ""
		buff += ind + "/*  {}  */".format(chr(self.char_num))
		buff += ind + "(const font_char_t []){{"

		ind = "\n"+"\t"*(indent+1)
		buff += ind + ".character={},".format(self.char_num)
		buff += ind + ".width={},".format(self.width)
		buff += ind + ".height={},".format(self.height)
		buff += ind + ".padding={"

		ind = "\n"+"\t"*(indent+2)
		buff += ind + ".left={},".format(self.padding_left)
		buff += ind + ".right={},".format(self.padding_right)
		buff += ind + ".bottom={},".format(self.padding_bottom)
		buff += ind + ".top={},".format(self.padding_top)

		ind = "\n"+"\t"*(indent+1)
		buff += ind + "},"
		if self.width == 0:
			buff += ind + ".data=NULL,"
		else:
			buff += ind + ".data=(const uint8_t [{}]){{".format(self.height * self.width)

			ind = "\n"+"\t"*(indent+2)
			for offset in range(\
				self.padding_left + self.raw_width*self.padding_top,\
				self.padding_left + self.raw_width*(self.padding_top+self.height),\
				self.raw_width):
				for pix in self.raw_bitmap[offset:offset+self.width]:
					buff += "0x{:02x}, ".format(pix)
				buff += ind
			ind = "\n"+"\t"*(indent+1)
			buff += ind + "},"
		
		

		ind = "\n"+"\t"*(indent)
		buff += ind + "}},"
		return buff

bitmap_size_total_before = 0
bitmap_size_total_after = 0

while True:
	line = raw.readline()
	if not line:
		break
	line = line.replace("\n","")
	
	if line.startswith("* name: "):
		font_name = line.replace(" ", "").split(":")[1]
		print(font_name)
	
	if line.startswith("static const uint8_t image_data_"):
		# print("found start of char bitmap...")

		char_num = int(line.strip().split(" ")[3].split("_")[-1][:4], 16)
		# print(chr(char_code))
		if ascii_offset == None:
			ascii_offset = char_num

		bitmap = []
		# parye bitmap
		while True:
			line = raw.readline().replace("\n","")
			# print(line)
			if line == "};":
				break
			bitmap+=[int(value.strip(), 16) for value in line.split(",") if value.strip() != ""]

		# parse bitmap parameters
	if line.startswith("static const tImage "):
		# print("found char bitmap params...")
		line = raw.readline().replace("\n","")
		#    48, 59, 8};
		params = line.strip()[:-2].split(",")
		width, height, bpp = [int(value.strip(), 10) for value in params if value.strip() != ""]

				
		# print(bitmap)
		# print(width, height, bpp)
		characters.append(CharacterBitmap(char_num, bitmap, width, height))
		bitmap_size_total_before += characters[-1].raw_width*characters[-1].raw_height
		bitmap_size_total_after += characters[-1].width*characters[-1].height

if args.header:
	header_content="""#ifndef _FONT_TYPES_LIB
	#define _FONT_TYPES_LIB

	#include <inttypes.h>

	typedef struct{
		char character;
		uint16_t width;
		uint16_t height;
		const struct{
			uint16_t left;
			uint16_t right;
			uint16_t top;
			uint16_t bottom;
		}padding;
		const uint8_t *const data;
	}font_char_t;

	typedef struct{
		const uint8_t offset;
		const font_char_t *const *const characters;
	}font_t;

#endif
	"""
	hfile=open("font_types.h", "w")
	hfile.writelines(header_content)
	hfile.close()

source_contents="""#include "font_types.h"

#ifndef NULL
	#define NULL ((void *)0)
#endif

const font_t font_{} ={{
	.offset={},
	.characters=(const font_char_t *[]){{
""".format(font_name, ascii_offset)
# export
for ch in characters:
	source_contents+=ch.export(1)

source_contents += """\n\tNULL
	}
};
"""

cfile = open("font_minimized_{}.c".format(font_name), "w")
cfile.writelines(source_contents)
cfile.close()

print("SUM,\n\toriginal: {:6}\n\treduced:  {:6}\n\tresult:   {:6.2f} %".format( bitmap_size_total_before, bitmap_size_total_after, bitmap_size_total_after/bitmap_size_total_before*100))
