####
 # File Name: getopts.sh
 #
 # CopyLeft (C) 2025, Picasso's Fantasy Notepad. All rights reserved.
 #
 # Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 #
 # Version: 1.0.0.build070825
 #
 # Date: 2025 / 07 / 08
 #
 # Description: 
 #              1. 這一個範例呈現了 Shell Script 當中 getopts 的用法，類似 C 語言裡的 getopt(); 函式。
 #              2. ":a:de:hi:no:tu:"
 #                 第 1 個 ':' 表示可以忽略錯誤；
 #                 a, e, i, o, u 後面的 ':' 代表 -a, -e, -i, -o, -u 後面可以接 1 個參數 ${OPTARG}；
 #                 d, h, n, t 後面沒有 ':' 表示不可以接參數。
 #                 ${OPTIND} 則是指現在所指到的位置。
 #              3. Shell Script 的 getopts 有點笨：
 #                 ./getopts.sh -a AAA -b -d -e EEE -f -h -i III -j -n -o OOO -p -t -u UUU ----> 可以得到正確的結果
 #                 ./getopts.sh -a AAA b -d -e EEE ----> -a 後面多了第 2 個參數，程式解譯到第 3 個參數 'b' 就停止了，就算後面的 -d, -e 正確也不會繼續執行。
 #
 #
######

#!/bin/bash - 

echo original parameters=[$*]

echo original OPTIND=[${OPTIND}]

while getopts ":a:de:hi:no:tu:" opt; do
	case ${opt} in
		a | e | i | o | u)
			echo "This is -${opt} option, OPTARG=${OPTARG}; OPTIND=${OPTIND}"
		;;
		d | h | n | t)
			echo "This is -${opt} option, OPTARG=${OPTARG}; OPTIND=${OPTIND}"
		;;
		*)
			echo "ERROR: Got unknown option!! OPTARG=${OPTARG}; OPTIND=${OPTIND}"
		;;
	esac
done

shift $((${OPTIND} - 1))

exit 0;
