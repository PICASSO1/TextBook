#!/bin/bash

#
#	File Name: until-loop.sh
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
#	1. 這一個*.sh檔案，示範了Shell Script中Until Loop迴圈的用法。
#	2. Until Loop的用法和While Loop的用法相反：
#		a). While Loop是一直做 (true)，做到條件不成立時 (false)才跳出迴圈；
#		b). Until Loop是一直判斷false的條件，直到真 (true)時才離開迴圈。
#	3. C語言中有3種迴圈：for, while, do-while，要了解它們之間的差異；
#	4. Shell Script中也有3種迴圈：for, while, until，也要了解他們之間的不同！！
#

foo=100

until who | grep "$1" 2> /dev/null 1>&2
do
	sleep 6
done

echo -e \\a
echo "**** \"$1\" has just logged in!! ****"

exit 0
