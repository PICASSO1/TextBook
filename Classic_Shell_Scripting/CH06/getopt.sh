####
 # File Name: getopt.sh
 #
 # CopyLeft (C) 2025, Picasso's Fantasy Notepad. All rights reserved.
 #
 # Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 #
 # Version: 1.0.0.build071425
 #
 # Date: 2025 / 07 / 14
 #
 # Description: 
 #              1. 這一個範例呈現了 Shell Script 當中 getopt 的用法，類似 C 語言裡的 getopt_long(); 函式。
 #              2. Shell Script 裡的 getopts 和 getopt 都不是很好用，跟 C 語言比起來，並不怎麼靈活。
 #
######

#!/bin/bash - 

# 先用 getopt 分別定義長短參數：-a 或 --help
# -o 定義短參數 -a, -e, -i, -o, -u
# -l 定義長參數 --help, --version
# 最前面的 ':' 代表可以忽略錯誤；但是僅能限用於短參數的 -o ，長參數 -l 不得使用！
# 參數後面的 ':' 「一定」要接上 1 個非 '-' 或 "--" 開頭的參數
# "--" 雙破折號是 getopt 的分隔標記符，表示「參數清單的開始」，防止誤判
# 例如：如果你有一個參數剛好叫 "--" 或像 "-v-abc" 這種奇怪字串，加 -- 可以避免它被當作 option 錯誤解析。
PARSED=$(getopt -o :a:de:hi:no:tu: -l all,delete:,edit:,help,interrupt,num:,total,options: -- "${@}")

# 將解析後的結果設回 $@
eval set -- "${PARSED}"

# 進入處理迴圈
while true; do
    case "${1}" in
		-a | -e | -i | -o | -u | --delete | --edit | --num | --options)
			echo "This is ${1} option, OPTARG=${2}"
			shift 2
		;;
		-d | -h | -n | -t | --all | --help | --interrupt | --total)
			echo "This is ${1} option, and without any OPTARG."
			shift 1
		;;
        *)
			echo "Unknown option: ${1}"
			exit 1
		;;
	esac
done

exit 0;
