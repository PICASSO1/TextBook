#!/bin/bash

#
#	File Name: and-or.sh
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
#	1. 這一個*.sh檔案，示範了Shell Script中And (&&), Or (||)的用法。
#

touch ./TEST.TXT

if [ -f ./TEST.TXT ] || [ -f TEXT.INI ]; then
	touch ./TEXT.INI
	echo "Create the file: TEXT.INI "
fi

if [ -f ./TEST.TXT ] && [ -f TEXT.INI ]; then
	rm -vf ./TEST.TXT ./TEXT.INI 2> /dev/null 1>&2
	echo "Remove the files: TEST.TXT, TEXT.INI"
fi

exit 0
