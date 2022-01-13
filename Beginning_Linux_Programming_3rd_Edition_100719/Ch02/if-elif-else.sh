#!/bin/bash

#
#	File Name: if-elif-else.sh
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
#	1. 這一個*.sh檔案，示範了Shell Script中if-elif-else的用法。
#

timeofday=""

echo "Is it morning?? Please answer \"yes\" or \"no\": "
read timeofday

if [ "$timeofday" = "yes" ]; then
	echo "Good morning!! "
elif [ "$timeofday" = "no" ]; then
	echo "Good afternoon!! "
else
	echo "Good evening!! "
	exit 1
fi

exit 0
