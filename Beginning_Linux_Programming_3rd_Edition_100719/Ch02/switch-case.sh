#!/bin/bash

#
#	File Name: switch-case.sh
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
#	1. 這一個*.sh檔案，示範了Shell Script中Switch-Case的用法。
#	2. Case-In就相當於C語言中的Switch-Case用法；
#	3. ;; 相當於C語言中的break;
#	4. 萬用字元, *), 相當於C語言中Switch-Case的default，建議要加上去，以利於爾后的除錯！！
#

timeofday=""

echo "Is it morning?? Please answer: "
read timeofday

case "$timeofday" in
	[Yy][Ee][Ss] | [Yy])
		echo "0. Good morning!! "
		;;
	[Nn][Oo] | [Nn])
		echo "2. Good afternoon!! "
		;;
	*)
		echo "Oooh!! What the fuck that?? "
		;;
esac

exit 0
