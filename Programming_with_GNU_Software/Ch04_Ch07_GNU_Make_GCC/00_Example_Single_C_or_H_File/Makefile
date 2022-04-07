###
 # File Name: Makefile
 #
 # CopyLeft (C) 2022, Picasso's Fantasy Notepad. All rights reserved.
 #
 # Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 #
 # Version: 1.0.0.build040722
 #
 # Date: 2022 / 04 / 07
 #
 # Description: 
 # 1. 這一個最簡單的 Makefile 範例；只有單獨一個*.C檔的情況之下。
 #
 # 2. Line: 33: "$(OBJS): %.o: %.c" 的意思是：物件檔 main.o 會是由 main.c 而產生的。
 #
 # 3. '@': 不顯示該行的執行命令。
 #
 # 4. '-': 倘若該行命令執行錯誤，也要繼續執行下去。
 #
######

GCC := gcc
CFLAGS := -o
OBJS := main.o
EXEC := main
RM := rm -rf

.PHONY: all
all: $(EXEC)

$(EXEC): $(OBJS)
	@-$(GCC) $(CFLAGS) $(EXEC) $(OBJS)

$(OBJS): %.o: %.c
	@-$(GCC) -c $< $(CFLAGS) $@

.PHONY: clean cleanall install print tar dist TAGS check test
clean:
	@-$(RM) *.o *.S

cleanall: clean
	@-$(RM) $(EXEC) 

install:

print:

tar:

dist:

TAGS:

check: 

test:
