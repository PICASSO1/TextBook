###
 # File Name: Makefile
 #
 # CopyLeft (C) 2022, Picasso's Fantasy Notepad. All rights reserved.
 #
 # Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 #
 # Version: 1.0.0.build042922
 #
 # Date: 2022 / 04 / 29
 #
 # Description: 
 # 1. 2 個不是很複雜的 *.c 檔案，用來呈現組譯成 Assembly 是長成啥樣子.... 但是，這兩個 Assembly 卻比前一個章節要難多了！自己也沒有看得很懂 .... 
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

BIN := define inline
OBJS := define.o inline.o
ASS := define.S inline.S
INSTRUCTION := define.i inline.i

CFLAGS := -o
DEBUG := -ggdb

INCS := 
LIB := 
STATIC_LIB := 

.PHONY: all
all: $(BIN)

$(BIN): $(OBJS)
#	$(GCC) $(CFLAGS) $(BIN) $(OBJS)
	/usr/bin/gcc -o define define.o
	/usr/bin/gcc -o inline inline.o

$(OBJS): %.o: %.S
#	$(GCC) -c $< -fverbose-asm $(CFLAGS) $@
	/usr/bin/gcc -c define.S -fverbose-asm -o define.o
	/usr/bin/gcc -c inline.S -fverbose-asm -o inline.o

#$(ASS): %.S: %.i
#	$(GCC) -S $< $(CFLAGS) $@
#	/usr/bin/gcc -S define.i -o define.S
#	/usr/bin/gcc -S inline.i -o inline.S

#$(INSTRUCTION): %.i: %.c
#	$(GCC) -E $< $(CFLAGS) $@
#	/usr/bin/gcc -E define.c -o define.i
#	/usr/bin/gcc -E inline.c -o inline.i

.PHONY: clean cleanall install print tar dist TAGS check test
clean:
	@-$(RM) *.o

cleanall: clean
	@-$(RM) $(BIN) 

install:

print:

tar:

dist:

TAGS:

check: 

test:
