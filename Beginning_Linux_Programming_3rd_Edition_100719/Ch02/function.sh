#!/bin/bash

#
#	File Name: function.sh
#
#	CopyLeft (C) 2016; All rights reserved.
#
#	Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
#
#	Version: 0.0.1.build021617
#
#	Date: 2016 / 02 / 17
#
#	Description: 
#	1. 這一個*.sh檔案，示範了Shell Script中函式 (Function)的用法。
#	2. 在主程式之中，被傳遞的參數是哪些 (1st block);
#	3. 是如何傳遞參數給函式??
#	4. 在函式中，被傳遞的參數又是哪些 (2nd block);
#	5. 在函式中宣告變數必須加上"local"關鍵字 (3rd block)！！
#	6. 不足之處：不清楚函式的回傳值該如何接收？？
#	7. 測試方法: ./function.sh abcd efgh ijkl
#

myFunc0() {
	echo "myFunc0(), \$@ = " $@
	echo "myFunc0(), \$0 = " $0
	echo "myFunc0(), \$1 = " $1
	echo "myFunc0(), \$2 = " $2
	echo "myFunc0(), \$# = " $#
	return;
}

myFunc1() {
	local a=$@; b=$0; c=$1; d=$2; e=$#
	echo "myFunc1(), \$@ = " $a
	echo "myFunc1(), \$0 = " $b
	echo "myFunc1(), \$1 = " $c
	echo "myFunc1(), \$2 = " $d
	echo "myFunc1(), \$# = " $e
	return;
}

echo "This scripting starting.... "
echo $0 ", \$@ = " $@
echo $0 ", \$0 = " $0
echo $0 ", \$1 = " $1
echo $0 ", \$2 = " $2
echo $0 ", \$3 = " $3
echo $0 ", \$# = " $#
echo -en "\n"

myFunc0 $2 $3
echo -en "\n"

myFunc1 $1 $0
echo -en "\n"

echo "DONE!! "

exit 0
