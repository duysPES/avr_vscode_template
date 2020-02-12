
# Name: Makefile
# Author: <insert your name here>
# Copyright: <insert your copyright message here>
# License: <insert your license reference here>

# DEVICE ....... The AVR device you compile for
# CLOCK ........ Target AVR clock rate in Hertz
# OBJECTS ...... The object files created from your source files. This list is
#                usually the same as the list of source files with suffix ".o".
# PROGRAMMER ... Options to avrdude which define the hardware you use for
#                uploading to the AVR and the interface where this hardware
#                is connected.
# FUSES ........ Parameters for avrdude to flash the fuses appropriately.

DEVICE     	= atmega2560
CLOCK      	= 16000000
PROGRAMMER 	= -cwiring -P /dev/ttyACM0
CONF 	   	= /etc/avrdude.conf
FUSES      	= -U lfuse:w:0x64:m -U hfuse:w:0xdd:m -U efuse:w:0xff:m
SRC_DIR 	= src

SRC 		:= $(shell find $(SRC_DIR) -name '*.cpp') 
SRC         += $(shell find $(SRC_DIR) -name '*.c')

 
OBJ_DIR		:= obj
OBJECTS    	= $(OBJ_DIR)/main.o

LIB_DIR		:= lib
CFLAGS		:= -Wall -Os

######################################################################
######################################################################

# Tune the lines below only if you know what you are doing:

AVRDUDE = avrdude $(PROGRAMMER) -p $(DEVICE)
COMPILE = avr-g++ $(CFLAGS) -DF_CPU=$(CLOCK) -mmcu=$(DEVICE)

# symbolic targets:
all:	main.hex

.c.o:
	$(COMPILE) -c $< -o $@

.S.o:
	$(COMPILE) -x assembler-with-cpp -c $< -o $@
# "-x assembler-with-cpp" should not be necessary since this is the default
# file type for the .S (with capital S) extension. However, upper case
# characters are not always preserved on Windows. To ensure WinAVR
# compatibility define the file type manually.

.c.s:
	$(COMPILE) -S $< -o $@

flash:	all
	$(AVRDUDE) -C$(CONF) -D -U flash:w:$(OBJ_DIR)/main.hex:i

fuse:
	$(AVRDUDE) $(FUSES)

install: flash fuse

# if you use a bootloader, change the command below appropriately:
load: all
	bootloadHID main.hex

clean:
	rm -f $(OBJ_DIR)/*

main.o:
	@echo $(SRC)
	$(COMPILE) $(SRC) -o ${OBJ_DIR}/main.elf

# file targets:
main.elf: main.o
	# $(COMPILE) -o $(OBJ_DIR)/main.elf $(OBJECTS)

main.hex: main.elf
	rm -f main.hex
	avr-objcopy -j .text -j .data -O ihex $(OBJ_DIR)/main.elf $(OBJ_DIR)/main.hex
	avr-size -C --mcu=$(DEVICE) $(OBJ_DIR)/main.elf

# If you have an EEPROM section, you must also create a hex file for the
# EEPROM and add it to the "flash" target.

# Targets for code debugging and analysis:
disasm:	main.elf
	avr-objdump -SlC $(OBJ_DIR)/main.elf

cpp:
	$(COMPILE) -E main.c