####
 # File Name: bash_variables_0.sh
 #
 # CopyLeft (C) 2023, Picasso's Fantasy Notepad. All rights reserved.
 #
 # Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 #
 # Version: 1.0.0.build083123
 #
 # Date: 2023 / 08 / 31
 #
 # Description: 紀錄一下 Bash 的環境變數的基本用法；有些很難懂的未必常用到。Ref: 
 #              https://www.gnu.org/software/bash/manual/html_node/
 #              https://www.gnu.org/software/bash/manual/bash.pdf
 #
######

#!/bin/bash - 

# 目前是使用那一種 Shell 及其檔案位置
echo "01. \$BASH:" $BASH
echo -en "\n"

# 目前正在執行的 Shell Script 檔案，等同於 ${0}；但某些情況下有特殊用途
echo "02. \$BASH_SOURCE:" $BASH_SOURCE
echo "02. \$0:" $0
echo -en "\n"

# 查看目前此一 Shell 的版本號；執行 /usr/bin/bash --version 亦可得到相同的結果
echo "03. \$BASH_VERSION:" $BASH_VERSION
echo -en "\n"

# 此一變數類似 BASH_VERSION 的用法，但是分的更細：
echo "04. \$BASH_VERSINFO[0] (Major version):" ${BASH_VERSINFO[0]}
echo "04. \$BASH_VERSINFO[1] (Minor version):" ${BASH_VERSINFO[1]}
echo "04. \$BASH_VERSINFO[2] (Patch Level):" ${BASH_VERSINFO[2]}
echo "04. \$BASH_VERSINFO[3] (Build version):" ${BASH_VERSINFO[3]}
echo "04. \$BASH_VERSINFO[4] (Release Status):" ${BASH_VERSINFO[4]}
echo "04. \$BASH_VERSINFO[5] (MACHTYPE value):" ${BASH_VERSINFO[5]}
echo -en "\n"

# 目前此一檔案所在的位置
echo "05. \$PWD:" $PWD
echo -en "\n"

# 當執行此一 Shell Script 時的 PID，等同於 ${$}
echo "06. \$BASHPID:" $BASHPID
echo "06. \$$:" $$
echo -en "\n"

# 呼叫此一 Shell Script 的 Parent PID；可用 ps auwx | grep "bash" 查驗
echo "07. \$PPID:" $PPID
echo -en "\n"

# 類似 $BASH ；但會與 /etc/passwd | grep "${username}" 的最後一個欄位相同
# picasso:x:1000:1000:Picasso,,,:/home/picasso:/bin/bash
echo "08. \$SHELL:" $SHELL
echo -en "\n"

# 上一個工作的資料目錄，等同於："cd -"
echo "09. \$OLDPWD:" $OLDPWD
echo -en "\n"

# 目前所使用的語系
echo "10. \$LANG:" $LANG
echo -en "\n"

# 執行此一 Shell Script 時所帶進來的參數，例：./bash_variables_0.sh 12 34 56 78 90 AB CD EF
# 會得到 8 ；等同於 ${#}
echo "11. \$BASH_ARGC:" $BASH_ARGC
echo "11. \$#:" $#
echo -en "\n"

# 特殊用法的環境變數：當執行 Shell Script 時，所帶進來的參數會依序地放進 Stack，
# 例如：./bash_variables_0.sh 12 34 56 78 90 AB CD EF
# 而 $BASH_ARGV 會指到 Stack 的最頂端，即 "EF" 
echo "12. \$BASH_ARGV:" $BASH_ARGV
echo -en "\n"

# Argument Variable 第一個元素，等同於 $BASH_SOURCE 和 ${0}
echo "13. \$BASH_ARGV0:" $BASH_ARGV0
echo "13. \$0:" $0
echo -en "\n"

# 執行到此一 command 的所在行數：類似 C 的 __LINE__ 巨集
echo "14. \$LINENO:" $LINENO
echo -en "\n"

exit 0
