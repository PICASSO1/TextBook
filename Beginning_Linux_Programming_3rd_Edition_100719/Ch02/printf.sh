#!/bin/bash

val=15
key=G
string="Hello!! World!! "

printf "%s \n" $string
# 使用printf的字串中的變數若有空白鍵 (Space)，會被當成換行字元 (\n)....

printf "%s %d\t%c\t%%\n" "Hi, There!!" $val $key
# 若不是透過變數的方式所取得的字串，則無此一問題！！

exit 0
