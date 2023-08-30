####
 # File Name: array1.sh
 #
 # CopyLeft (C) 2023, Picasso's Fantasy Notepad. All rights reserved.
 #
 # Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 #
 # Version: 1.0.0.build083023
 #
 # Date: 2023 / 08 / 30
 #
 # Description: 這個範例 (example)呈現了當陣列 (array)傳遞給函式 (function)時的處理方式。
 #
######

#!/bin/bash - 

array=(0 1 2 3 4 5)

function example()
{
	local idx=-1
	# 要把傳遞近來的陣列，設定給函式內部的陣列；
	# 注意！不要加雙引號 "$@" 因為會被當成字串設定給陣列，即：arr[0]="0 1 2 3 4 5"
	local arr=($@)

	# 這裡的陣列長度 ${#arr[*]} 不要加上雙引號，因為也會變成字串，即：idx < "6"
	for ((idx = 0; idx < ${#arr[*]}; idx++)); do
		echo "example(): \${arr[$idx]}:" "${arr["$idx"]}"
	done

	return;
}

# 把整個陣列傳遞給函式
example "${array[*]}"

exit 0
