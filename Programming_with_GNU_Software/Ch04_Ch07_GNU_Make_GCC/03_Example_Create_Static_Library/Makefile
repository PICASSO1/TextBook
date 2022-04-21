###
 # File Name: Makefile
 #
 # CopyLeft (C) 2022, Picasso's Fantasy Notepad. All rights reserved.
 #
 # Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 #
 # Version: 1.0.0.build041022
 #
 # Date: 2022 / 04 / 10
 #
 # Description: 
 # 1. 這是一個簡單地 Static library / Architecture (靜態函式庫 / 靜態架構)的範例寫法：
 #    - gcc -c main.c -o main.o
 #    - gcc -c funcX.c -o funcX.o
 #    - ar -crsv libfunc.a func3.o func4.o func5.o
 #    - gcc -o main main.o func1.o func2.o -static libfunc.a
 #
 # 2. 除此之外，ar 指令還有一些其他的用法︰
 #    a). 更新函式庫︰
 #    - ar -crs libfunc.a func4.o func5.o
 #    - ar -rs libfunc.a func3.o ----> 把 func3.o 新增到靜態函式庫
 #
 #    b). 刪除函式庫︰
 #    - ar -ds libfunc.a func4.o ----> 把 func4.o 從靜態函式庫中移除
 #
 #   b). 讀取函式庫︰
 #    - ar -x libfunc.a func5.o ----> 把 func5.o 從靜態函式庫中讀取出來；只是「讀取」，並不是「刪除」
 #
 # 3. 早期的 UNIX like System 還有一個 ranlib 的指令工具，那是因為之前的 ar 指令在「更新」或「刪除」靜態函式庫成員時 (*.o)，並不會跟著更新靜態函式庫表頭 (header)的索引值 (index)︰
 #    導致於明明在靜態函式庫中已新增了，但在最後的 Linking 階段還是會找不到相關成員 (*.o)。但現今的 ar 指令已取代此一功能。
 #
######

GCC := /usr/bin/gcc
CFLAGS := -o
OBJS1 := main.o func1.o func2.o
OBJS2 := func3.o func4.o func5.o
BIN := main
RM := /usr/bin/rm -rf
AR := /usr/bin/ar
STATIC_LIB := libfunc.a

.PHONY: all
all: $(BIN)

$(BIN): $(OBJS1) $(STATIC_LIB)
	$(GCC) $(CFLAGS) $(BIN) $(OBJS1) $(STATIC_LIB)
#	gcc -o main main.o func1.o func2.o libfunc.a

$(OBJS1): %.o: %.c
	@-$(GCC) -c $< $(CFLAGS) $@
#	gcc -c func1.c -o func1.o
#	gcc -c func2.c -o func2.o
#	gcc -c main.c -o main.o

$(OBJS2): %.o: %.c
	@-$(GCC) -c $< $(CFLAGS) $@
#	gcc -c func3.c -o func3.o
#	gcc -c func4.c -o func4.o
#	gcc -c func5.c -o func5.o

$(STATIC_LIB): $(OBJS2)
	$(AR) -crsv $(STATIC_LIB) $(OBJS2)
#	ar -crs libfunc.a func3.o func4.o func5.o

.PHONY: clean cleanall install print tar dist TAGS check test
clean:
	@-$(RM) *.o *.S *.a

cleanall: clean
	@-$(RM) $(BIN) 

install:

print:

tar:

dist:

TAGS:

check: 

test:
