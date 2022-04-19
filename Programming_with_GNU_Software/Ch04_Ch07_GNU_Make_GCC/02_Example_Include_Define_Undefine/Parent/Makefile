###
 # File Name: Makefile
 #
 # CopyLeft (C) 2022, Picasso's Fantasy Notepad. All rights reserved.
 #
 # Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 #
 # Version: 1.0.0.build040922
 #
 # Date: 2022 / 04 / 09
 #
 # Description: 
 # 1. C 語言當中的前置處理器 (CPP)："#include", "#define" & "#undef" 除了在 *.C 檔中撰寫之外；也可以透過 gcc 的參數："-D" (Define), "-I" (Include) & "-U" (Undefine)來傳遞，可以達到一樣的效果！
 #
 #####

GCC := /usr/bin/gcc
CFLAGS := -o
OBJS := main.o func1.o func2.o
BIN := main
RM := /usr/bin/rm -rf

AR := /usr/bin/ar
INCS := 
LIB := 
STATIC_LIB := 

.PHONY: all
all: $(BIN)

$(BIN): $(OBJS)
	@-$(GCC) $(CFLAGS) $(BIN) $(OBJS)

$(OBJS): %.o: %.c
#	@-$(GCC) -c $< $(CFLAGS) $@
	gcc -c func1.c -o func1.o -D AAAAA -I./Child/
	gcc -c func2.c -o func2.o -U BBBBB -I../
	gcc -c main.c -o main.o -I../ -D CCCCC="\"Hell!! World!! \"" 

.PHONY: clean cleanall install print tar dist TAGS check test
clean:
	$(RM) *.o *.S

cleanall: clean
	$(RM) $(BIN) 

install:

print:

tar:

dist:

TAGS:

check: 

test:
