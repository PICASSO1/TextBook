###
 # File Name: Makefile
 #
 # CopyLeft (C) 2022, Picasso's Fantasy Notepad. All rights reserved.
 #
 # Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 #
 # Version: 1.0.0.build040822
 #
 # Date: 2022 / 04 / 08
 #
 # Description: 
 # 1. 倘若有２個以上的 *.C 檔，會產生許多個 *.O 檔，那這些物件 (Object)檔也通通都要新增到 $(OBJS) 變數。
 #
 # 2. 而 "%.o: %.c" 語法會自動地找到相對應的檔案，進而產生相關地物件檔案。
 #
 # 3. 
 #
 # 4. 
 #
######

GCC := gcc
CFLAGS := -o
OBJS := main.o define.o
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
	@-$(RM) *.o

cleanall: clean
	@-$(RM) $(EXEC)

install:

print:

tar:

dist:

TAGS:

check: 

test:
