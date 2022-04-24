###
 # File Name: Makefile
 #
 # CopyLeft (C) 2022, Picasso's Fantasy Notepad. All rights reserved.
 #
 # Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 #
 # Version: 1.0.0.build042322
 #
 # Date: 2022 / 04 / 23
 #
 # Description: 
 # 1. 一個非常簡單的 *.c 檔案，並無太大的意義；主要是用來編譯成 Assembly。
 #
######

GCC := /usr/bin/gcc
CFLAGS := -o
OBJS := main.o
BIN := main
RM := /usr/bin/rm -rf
DEBUG := -g

AR := /usr/bin/ar
INCS := 
LIB := 
STATIC_LIB := 
LDD := /usr/bin/ldd

.PHONY: all
all: $(BIN)

$(BIN): $(OBJS)
	$(GCC) $(CFLAGS) $(BIN) $(OBJS)

$(OBJS): %.o: %.c
#	$(GCC) -c $< $(CFLAGS) $@
#	$(GCC) -E main.c $(CFLAGS) main.i
#	$(GCC) -S main.i $(CFLAGS) main.S
#	$(GCC) -S $(DEBUG) ./main.i $(CFLAGS) ./main.S.G
	$(GCC) -c main.S -fverbose-asm $(CFLAGS) main.o

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
