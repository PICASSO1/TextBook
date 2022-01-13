#!/bin/bash

#
#	File Name: while-loop.sh
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
#	1. 這一個*.sh檔案，示範了Shell Script中While Loop迴圈的用法。
#	2. For Loop適用於"字串 (string)"；而While Loop較適用於"數值 (value)"；
#	3. foo=$(($foo + 1))，就相當於C語言中的"foo++", "foo = foo + 1"用法。
#

foo=0

while [ "$foo" -le 20 ]
do
	echo $foo. "Here we go again!! "
	foo=$(($foo+1))
done

exit 0
