#!/bin/bash

#
#	File Name: for-loop.sh
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
#	1. 這一個*.sh檔案，示範了Shell Script中For Loop迴圈的用法；有2個範例，視需求增刪註解。
#	2. 關鍵字for後面接的是變數，會把in後面的東西依序地存在變數之中；
#	3. 可試試有無加上雙引號""的差別效果；
#	4. 2nd個範例會把此一目錄下的所有*.sh檔案都秀出來!!
#

filename=""

#for filename in "abcd efgh ijkl"
#do
#	echo $filename
#done
#
#exit 0

for filename in $(ls ./*.sh)
do
	echo $filename
done

exit 0

# 在Shell Script中變數僅需要在前面加上$即可；和GNU Make不一樣，GNU Make則是$()
# 在Shell Script中，$()的用法是"將Shell Script的指令結果回傳回來"；而GNU Make的用法則是$(shell ls -l)
# 要注意這兩種程式語言的差異！！
