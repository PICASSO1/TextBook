####
 # File Name: arguments.sh
 #
 # CopyLeft (C) 2023, Picasso's Fantasy Notepad. All rights reserved.
 #
 # Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 #
 # Version: 1.0.0.build080723
 #
 # Date: 2023 / 08 / 07
 #
 # Description: 
 #              1. 這個 Shell Script 紀錄了 shift 的用法；後面可以接上一個參數；若無，預設值為1，即向左移一個參數。
 #              2. 此外，還順便記錄一些 Shell Script 常用的參數用法。
 #
######

#!/bin/bash - 

# $0: 一定是指本 Shell Script 檔案的名稱；絕對不會是函式名稱

# $1 .... $#: 無論是 Shell Script 檔案或是函式，所帶進來的參數

# $#: 所傳近來的參數總數

# $@, $*: 所傳近來的參數項目

# $$: 此一 Shell Script 運作時的 PID

# $?: 上一個指令的回傳值

# $!: 最近一個背景 (Background)命令的形成編號 (少用)

function exercise()
{
	echo "\$0:" $0
	echo "\$@:" $@
	echo "\$*:" $*
	echo "\$#:" $#
	echo "\$$:" $$
	echo "\$?:" $?
	echo "\$!:" $!

	while [ -n "$1" ]; do
		echo $1
		shift 2;
	done

	return;
}

exercise 1 2 3 4 5 6 7 8 9 "Hey!! " "Hello!! " "World!! "

exit 0;
