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
 # 1. 這是一個複雜地 Dynamic library / Shared Object (動態函式庫 / 共享物件檔)的範例寫法：
 #    - gcc -c main.c -o main.o
 #    - gcc -c func1.c -o func1.o
 #    - gcc -c func2.c -o func2.o
 #    - gcc -c -fPIC -Wall func3.c func4.c func5.c ----> 會產生 func3.o func4.o func5.o
 #
 #    - gcc -shared -Wl,-soname,libfunc.so.1 -o libfunc.so.1.0.0 func3.o func4.o func5.o ----> 產生 libfunc.so.1.0.0 檔案
 #      -shared: 指定我要將 *.o 檔案編譯成 Shared Library (*.so)
 #      -Wl: 表示 "-Wl" 後面的參數 "-soname", "libfunc.so.1" 在連結 (Linking) 階段時，傳遞給連結器 (/usr/bin/ld)
 #      -o: 這裡的 "-o" 表示我要將 *.o 檔案製作成 "libfunc.so.1.0.0" (/usr/lib/ 下真正的實體檔案)
 #      倘若沒有指定 "-soname,libfunc.so.1" 的話，在 gcc 連接階段時 (-l func) 指到的會是 "libfunc.so"；反之則是指到 "libfunc.so.1" (所以下面才會建立2組 Symbol Link)。
 #
 #    - sudo mv -vf libfunc.so.1.0.0 /usr/lib/ ----> 共享函式庫 (*.so) 的檔案一定要放在這個資料夾下
 #    - sudo ln -fsv /usr/lib/libfunc.so.1.0.0 /usr/lib/libfunc.so
 #    - sudo ln -fsv /usr/lib/libfunc.so.1.0.0 /usr/lib/libfunc.so.1 ----> 在 /usr/lib/ 資料夾下一定要產生這兩個 Symbol Link 
 #    - gcc -o main main.o func1.o func2.o -l func ----> 最後，產生可執行檔；用 "-l" 指定我要使用 /usr/lib/libfunc.so.1 這一個函式庫
 #
 # 2. 例外處理：
 #    - 假如：libXXXX.so.y.y.y 已經搬移到 /usr/lib/ 但在最後的 Linking 階段 (-l func)告訴你「找不到此一函式庫 (/usr/bin/ld: cannot find -lxxx)」或者是
 #    「error while loading shared libraries: libfunc.so.1: cannot open shared object file: No such file or directory」那是因為我們新增一個自訂的函式庫 (linfunc.so.1.0.0) 在系
 #     統 (/usr/lib/) ，但是系統統沒有更新函式庫索引。解決方案：
 #    - sudo pacman -Syu libxtst
 #    - sudo /sbin/ldconfig
 #
 # 3. 因為會牽扯到 /usr/lib/ 資料夾必須使用 root (Super User) 權限才能操作，所以執行時：sudo make (cleanall) 執行權限會由 Makefile 繼承至指令。
 #
######

GCC := /usr/bin/gcc
CFLAGS := -o
OBJS1 := main.o func1.o func2.o
OBJS2 := func3.o func4.o func5.o
EXEC := main
RM := /usr/bin/rm -rf

MAJOR := 1
MINOR := 0
RELEASE := 0
DYNAMIC_LIB := func
LIB_DIR := /usr/lib/
UNLINK := /usr/bin/unlink

.PHONY: all
all: $(EXEC)

$(EXEC): $(OBJS1) $(OBJS2) $(DYNAMIC_LIB)
	$(GCC) $(CFLAGS) $(EXEC) $(OBJS1) -l $(DYNAMIC_LIB)
#	gcc -o main main.o func1.o func2.o -l func

$(OBJS1): %.o: %.c
	$(GCC) -c $< $(CFLAGS) $@

$(OBJS2): 
	$(GCC) -c -fPIC -Wall func3.c func4.c func5.c
	$(GCC) -shared -Wl,-soname,lib$(DYNAMIC_LIB).so.$(MAJOR) $(CFLAGS) lib$(DYNAMIC_LIB).so.$(MAJOR).$(MINOR).$(RELEASE) $(OBJS2)
#	gcc -shared -Wl,-soname,libfunc.so.1 -o libfunc.so.1.0.0 func3.o func4.o func5.o

$(DYNAMIC_LIB): $(OBJS2)
	mv -vf lib$(DYNAMIC_LIB).so.$(MAJOR).$(MINOR).$(RELEASE) $(LIB_DIR)
#	mv -vf libfunc.so.1.0.0 /usr/lib/
	ln -fsv $(LIB_DIR)lib$(DYNAMIC_LIB).so.$(MAJOR).$(MINOR).$(RELEASE) $(LIB_DIR)lib$(DYNAMIC_LIB).so
#	ln -fsv /usr/lib/libfunc.so.1.0.0 /usr/lib/libfunc.so
	ln -fsv $(LIB_DIR)lib$(DYNAMIC_LIB).so.$(MAJOR).$(MINOR).$(RELEASE) $(LIB_DIR)lib$(DYNAMIC_LIB).so.$(MAJOR)
#	ln -fsv /usr/lib/libfunc.so.1.0.0 /usr/lib/libfunc.so.1

.PHONY: clean cleanall install print tar dist TAGS check test
clean:
	$(RM) *.o *.S *.so.*

cleanall: clean
	-$(RM) $(EXEC) 
#	rm -vf main
	-$(UNLINK) $(LIB_DIR)lib$(DYNAMIC_LIB).so
#	unlink /usr/lib/libfunc.so
	-$(UNLINK) $(LIB_DIR)lib$(DYNAMIC_LIB).so.$(MAJOR)
#	unlink /usr/lib/libfunc.so.1
	-$(RM) $(LIB_DIR)lib$(DYNAMIC_LIB).so.$(MAJOR).$(MINOR).$(RELEASE)
#	rm -vf /usr/lib/libfunc.so.1.0.0

install:

print:

tar:

dist:

TAGS:

check: 

test:
