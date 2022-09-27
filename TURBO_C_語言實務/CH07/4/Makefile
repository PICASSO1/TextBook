###
 # File Name: Makefile
 #
 # CopyLeft (C) 2022, Picasso's Fantasy Notepad. All rights reserved.
 #
 # Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 #
 # Version: 1.0.0.build092722
 #
 # Date: 2022 / 09 / 27
 #
 # Description: 
 # 1. 
 #
######

# Compiler
GCC := /usr/bin/gcc
# Assembler
AS := /usr/bin/as
# Architecture, for create the Static Library
AR := /usr/bin/ar
# Linker
LDD := /usr/bin/ldd
# rm command .... 
RM := /usr/bin/rm -rf

BIN := main
OBJS := main.o
ASS := main.S
INSTRUCTION := main.i

CFLAGS := -O2 -Wall -Wextra -std=c99
DEBUG := -ggdb

INCS := 
LIB := m
STATIC_LIB := 

.PHONY: all
all: $(BIN)

$(BIN): $(OBJS)
	$(GCC) -o $(BIN) $(OBJS) -l$(LIB)

$(OBJS): $(ASS)
	$(GCC) -c $(CFLAGS) $< -fverbose-asm -o $@

$(ASS): $(INSTRUCTION)
	$(GCC) -S $< -o $@

$(INSTRUCTION): %.i: %.c
	$(GCC) -E $< -o $@

.PHONY: clean cleanall install print tar dist TAGS check test
clean:
	@-$(RM) *.i *.S *.o

cleanall: clean
	@-$(RM) $(BIN)

install:

print:

tar:

dist:

TAGS:

check: 

test:
