####
 # File Name: while_loop.sh
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
 #              1. 這一個*.sh檔案，示範了Shell Script中While Loop迴圈的用法。
 #              2. For Loop適用於"字串 (string)"；而While Loop較適用於"數值 (value)"；
 #              3. foo=$(($foo + 1))，就相當於C語言中的"foo++", "foo = foo + 1"用法。
 #
######

#!/bin/bash - 

FOO=0

while [ "${FOO}" -le 9 ]; do
	echo ${FOO}. "Hello!! World!! "
	FOO=$((${FOO}+1))
done

exit 0;
