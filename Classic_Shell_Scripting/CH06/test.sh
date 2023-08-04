####
 # File Name: test.sh
 #
 # CopyLeft (C) 2023, Picasso's Fantasy Notepad. All rights reserved.
 #
 # Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 #
 # Version: 1.0.0.build080423
 #
 # Date: 2023 / 08 / 04
 #
 # Description: 
 #              1. [ -' ' "" ] 此一語法等同於：test -' ' "" ；例：[ -n "$VAR" ]; 變數 $VAR 「一定要加上雙引號」，若 $VAR 為空值，語法變成：test -n 會產生不可預期的錯誤！
 #              2. 主要分類：
 #                 -n, -z: 判斷是否為 NULL 值
 #                 -c, -b, -S, -p, -d, -L, -h, -f: 判斷檔案類型
 #                 -e, -s: 判斷檔案是否存在，及是否為空檔案
 #                 -r, -w, -x: 判斷檔案能否讀取，寫入和執行
 #                 -u, -g: 判斷檔案是否 SUID & SGID
 #                 -t: [ -t "$FD" ]; 判斷 "$FD" (File Description, 檔案描述子)是否指到一個 TTY 設備？
 #
######

#!/bin/bash - 

# 若變數 VAR 不是 NULL 則為真
VAR=""
[ "$VAR" ] && {
	echo "01. The string \$VAR ISN'T null!! "
} || {
	echo "01. The string \$VAR IS null!! "
}

VAR="Hello!! World!! "
[ "$VAR" ] && {
	echo "02. The string \$VAR ISN'T null!! "
} || {
	echo "02. The string \$VAR IS null!! "
}

echo -en "\n"

##################################################

# 若變數 VAR 不是 NULL 則為真 (與上例相同)
VAR=""
[ -n "$VAR" ] && {
	echo "03. The string \$VAR ISN'T null!! "
} || {
	echo "03. The string \$VAR IS null!! "
}

VAR="Hello!! World!! "
[ -n "$VAR" ] && {
	echo "04. The string \$VAR ISN'T null!! "
} || {
	echo "04. The string \$VAR IS null!! "
}

echo -en "\n"

##################################################

# 若變數 VAR "是" NULL 則為真 (與上二例相反)
VAR=""
[ -z "$VAR" ] && {
	echo "05. The string \$VAR IS null!! "
} || {
	echo "05. The string \$VAR ISN'T null!! "
}

VAR="Hello!! World!! "
[ -z "$VAR" ] && {
	echo "06. The string \$VAR IS null!! "
} || {
	echo "06. The string \$VAR ISN'T null!! "
}

echo -en "\n"

##################################################

# 若變數 VAR 是字元設備檔 (Character Device)則為真
VAR="/dev/null"
[ -c "$VAR" ] && {
	echo "07. The device \"$VAR\" IS a Character Device!! "
} || {
	echo "07. The device \"$VAR\" ISN'T a Character Device!! "
}

echo -en "\n"

##################################################

# 若變數 VAR 是區塊設備檔 (Block Device)則為真
VAR="/dev/sda"
[ -b "$VAR" ] && {
	echo "08. The device \"$VAR\" IS a Block Device!! "
} || {
	echo "08. The device \"$VAR\" ISN'T a Block Device!! "
}

echo -en "\n"

##################################################

# 若變數 VAR 是網路 Socket 設備檔 (Socket Device)則為真
VAR="/run/udev/control"
[ -S "$VAR" ] && {
	echo "09. The device \"$VAR\" IS a Socket Device!! "
} || {
	echo "09. The device \"$VAR\" ISN'T a Socket Device!! "
}

echo -en "\n"

##################################################

# 若變數 VAR 是具名管線設備檔 (Named Pipe Device)則為真
VAR="/tmp/SciTE.24330.in"
[ -p "$VAR" ] && {
	echo "10. The device \"$VAR\" IS a Named Pipe Device!! "
} || {
	echo "10. The device \"$VAR\" ISN'T a Named Pipe Device!! "
}

echo -en "\n"

##################################################

# 若變數 VAR 是資料夾檔案 (Directory)則為真
VAR="/home/"
[ -d "$VAR" ] && {
	echo "11. The file \"$VAR\" IS a Directory!! "
} || {
	echo "11. The file \"$VAR\" ISN'T a Directory!! "
}

echo -en "\n"

##################################################

# 若變數 VAR 是符號連結檔 (Symbol Link)則為真 (等同於 "-h" )
VAR="/home/"
[ -L "$VAR" ] && {
	echo "12. The file \"$VAR\" IS a Symbol Link (\"-L\")!! "
} || {
	echo "12. The file \"$VAR\" ISN'T a Symbol Link (\"-L\")!! "
}

echo -en "\n"

##################################################

# 若變數 VAR 是符號連結檔 (Symbol Link)則為真 (等同於 "-L" )
VAR="/home/"
[ -h "$VAR" ] && {
	echo "13. The file \"$VAR\" IS a Symbol Link (\"-h\")!! "
} || {
	echo "13. The file \"$VAR\" ISN'T a Symbol Link (\"-h\")!! "
}

echo -en "\n"

##################################################

# 若變數 VAR 是一般檔案 (Files)則為真 (除了: -c, -b, -S, -p, -d, -L, -h 之外)
VAR="./test.sh"
[ -f "$VAR" ] && {
	echo "14. The file \"$VAR\" IS a general File!! "
} || {
	echo "14. The file \"$VAR\" ISN'T a general File!! "
}

echo -en "\n"

##################################################

# 若變數 VAR 代表的檔案存在 (Exist)則為真
VAR="./test.sh"
[ -e "$VAR" ] && {
	echo "15. The file \"$VAR\" IS Existed!! "
} || {
	echo "15. The file \"$VAR\" ISN'T Exist!! "
}

echo -en "\n"

##################################################

# 若變數 VAR 代表的檔案「不是空的」 (String, 表示有內容)則為真
VAR="./test.sh"
[ -s "$VAR" ] && {
	echo "16. The file \"$VAR\" ISN'T NULL!! "
} || {
	echo "16. The file \"$VAR\" IS NULL!! "
}

echo -en "\n"

##################################################

# 若變數 VAR 代表的檔案可以讀取 (Read)則為真
VAR="./test.sh"
[ -r "$VAR" ] && {
	echo "17. The file \"$VAR\" COULD Read!! "
} || {
	echo "17. The file \"$VAR\" COULDN'T Read!! "
}

echo -en "\n"

##################################################

# 若變數 VAR 代表的檔案可以寫入 (Write)則為真
VAR="./test.sh"
[ -w "$VAR" ] && {
	echo "18. The file \"$VAR\" COULD Write!! "
} || {
	echo "18. The file \"$VAR\" COULDN'T Write!! "
}

echo -en "\n"

##################################################

# 若變數 VAR 代表的檔案可以執行 (Executable)則為真
VAR="./test.sh"
[ -x "$VAR" ] && {
	echo "19. The file \"$VAR\" COULD Executable!! "
} || {
	echo "19. The file \"$VAR\" COULDN'T Executable!! "
}

echo -en "\n"

##################################################

# 若變數 VAR 代表的檔案有設定 SUID (Set User ID)則為真
VAR="./test.sh"
[ -u "$VAR" ] && {
	echo "20. The file \"$VAR\" IS already SUID!! "
} || {
	echo "20. The file \"$VAR\" ISN'T already SUID!! "
}

echo -en "\n"

##################################################

# 若變數 VAR 代表的檔案有設定 SGID (Set Group ID)則為真
VAR="./test.sh"
[ -g "$VAR" ] && {
	echo "21. The file \"$VAR\" IS already SGID!! "
} || {
	echo "21. The file \"$VAR\" ISN'T already SGID!! "
}

echo -en "\n"
