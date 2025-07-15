####
 # File Name: bash_variables_0.sh
 #
 # CopyLeft (C) 2025, Picasso's Fantasy Notepad. All rights reserved.
 #
 # Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 #
 # Version: 1.0.0.build071525
 #
 # Date: 2025 / 07 / 15
 #
 # Description: 紀錄一下 Bash 的環境變數的基本用法；有些很難懂的未必常用到。Ref: 
 #              https://www.gnu.org/software/bash/manual/html_node/
 #              https://www.gnu.org/software/bash/manual/bash.pdf
 #
######

#!/bin/bash - 

# 目前是使用那一種 Shell 及其檔案位置
echo "01. \${BASH}:" ${BASH}
echo -en "\n"

# 列出目前使用者的家目錄位置
echo "02. \${HOME}:" ${HOME}
echo -en "\n"

# Shell 當中設定的 Internal Field Separator (內部欄位分隔符)；預設值為 " \t\n" (Space、TAB, LF)。通常都是搭配 read, loop, set 等指令來使用。
echo "03. \${IFS}:" ${IFS}
echo -en "\n"

# OPTARG 和 OPTIND 是搭配 getopts 來使用的，單獨輸出並無任何效果。
# e.g. example.sh -a "Hello!! " -b "World!! " "Bye! Bye! " 此時：
# 當讀到 -a 時，會將 "Hello!! " 放進 OPTARG
# 當讀到 -b 時，會將 "World!! " 放進 OPTARG
# 因為 getopts 只能夠讀取一個參數，所以此時的 OPTIND 就會指到 "Bye! Bye! " (5)
echo "04. \${OPTARG}:" ${OPTARG}
echo "04. \${OPTIND}:" ${OPTIND}
echo -en "\n"

# 很常用的一個變數─列出所有的環境變數所指向的位置；其中以 ':' 作為分隔。
echo "05. \${PATH}:" ${PATH}
echo -en "\n"

# ${PATH} 是給執行檔用的，現今目錄下並無 "ls" 的指令，所以系統就會到 ${PATH} 所指定的目錄下去尋找；
# ${CDPATH} 是給 cd 指令專用的，現今目錄下並無 example 資料夾，當執行 cd example 時，系統就會到 ${CDPATH} 所指定的目錄下去尋找；
echo "06. \${CDPATH}:" ${CDPATH}
echo -en "\n"

# ${MAIL} 目前使用者的「信件檔案」位置。這個變數表示「目前使用者的信箱檔案」路徑。當有新的信件進來，Bash 可以用這個變數來監控變動，並自動顯示提示訊息。
# ${MAILPATH} 自訂多個信件檢查點。你可以設定一組路徑，讓 Bash 同時監控多個信件檔案，一旦有新郵件到達，Bash 就會提示你（例如登入時或執行完一條命令後）。
echo "07. \${MAIL}:" ${MAIL}
echo "07. \${MAILPATH}:" ${MAILPATH}
echo -en "\n"

# 目前正在執行的 Shell Script 檔案，等同於 ${0}；但某些情況下有特殊用途
echo "08. \${BASH_SOURCE}:" ${BASH_SOURCE}
echo "08. \${0}:" ${0}
echo -en "\n"

# 查看目前此一 Shell 的版本號；執行 /usr/bin/bash --version 亦可得到相同的結果
echo "09. \${BASH_VERSION}:" ${BASH_VERSION}
echo -en "\n"

# 此一變數類似 BASH_VERSION 的用法，但是分的更細：
echo "10. \${BASH_VERSINFO[0]} (Major version):" ${BASH_VERSINFO[0]}
echo "10. \${BASH_VERSINFO[1]} (Minor version):" ${BASH_VERSINFO[1]}
echo "10. \${BASH_VERSINFO[2]} (Patch Level):" ${BASH_VERSINFO[2]}
echo "10. \${BASH_VERSINFO[3]} (Build version):" ${BASH_VERSINFO[3]}
echo "10. \${BASH_VERSINFO[4]} (Release Status):" ${BASH_VERSINFO[4]}
echo "10. \${BASH_VERSINFO[5]} (MACHTYPE value):" ${BASH_VERSINFO[5]}
echo -en "\n"

# 目前此一檔案所在的位置
echo "11. \${PWD}:" ${PWD}
echo -en "\n"

# 當執行此一 Shell Script 時的 PID，等同於 ${$}
echo "12. \${BASHPID}:" ${BASHPID}
echo "12. \${$}:" ${$}
echo -en "\n"

# 呼叫此一 Shell Script 的 Parent PID；可用 ps auwx | grep "bash" 查驗
echo "13. \${PPID}:" ${PPID}
echo -en "\n"

# 類似 $BASH ；但會與 /etc/passwd | grep "${username}" 的最後一個欄位相同
# picasso:x:1000:1000:Picasso,,,:/home/picasso:/bin/bash
echo "14. \${SHELL}:" ${SHELL}
echo -en "\n"

# 上一個工作的資料目錄，等同於："cd -"
echo "15. \${OLDPWD}:" ${OLDPWD}
echo -en "\n"

# 目前所使用的語系
echo "16. \${LANG}:" ${LANG}
echo -en "\n"

# 執行此一 Shell Script 時所帶進來的參數，例：./bash_variables_0.sh 12 34 56 78 90 AB CD EF
# 會得到 8 ；等同於 ${#}
echo "17. \${BASH_ARGC}:" ${BASH_ARGC}
echo "17. \${#}:" ${#}
echo -en "\n"

# 特殊用法的環境變數：當執行 Shell Script 時，所帶進來的參數會依序地放進 Stack，
# 例如：./bash_variables_0.sh 12 34 56 78 90 AB CD EF
# 而 $BASH_ARGV 會指到 Stack 的最頂端，即 "EF" 
echo "18. \${BASH_ARGV:}" ${BASH_ARGV}
echo -en "\n"

# Argument Variable 第一個元素，等同於 $BASH_SOURCE 和 ${0}
echo "19. \${BASH_ARGV0}:" ${BASH_ARGV0}
echo "19. \${0}:" ${0}
echo -en "\n"

# 執行到此一 command 的所在行數：類似 C 的 __LINE__ 巨集
echo "20. \${LINENO}:" ${LINENO}
echo -en "\n"

exit 0
