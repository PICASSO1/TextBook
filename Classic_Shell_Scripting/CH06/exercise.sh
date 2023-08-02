####
 # File Name: exercise.sh
 #
 # CopyLeft (C) 2023, Picasso's Fantasy Notepad. All rights reserved.
 #
 # Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 #
 # Version: 1.0.0.build080223
 #
 # Date: 2023 / 08 / 02
 #
 # Description: 
 #
######

#!/bin/bash - 

# '#' 開頭代表是 Shell Script 的註解
# 而第一行的 "#!" 則表示要使用那一種 Shell；此例是使用 Bourne Shell (bash)
# 最後的 '-' 表示：執行此一 Shell 時，不帶任何參數；是為安全性上的考量

set -x

# "set -x" 表示執行此一 Shell Script 時，將所有的描述語法均呈現出來！

readonly VAR1="Hello!! "

# 關鍵字 "readonly" 表示宣告一個「唯讀」變數，類似C語言的 "const"

export VAR2="World!! "

# 關鍵字 "export" 表示：「將此一變數從這一個 Shell Script 匯出至環境變數」

function non_brackets()
{
	echo $1 $2 $3 $4 $5 $6 $7 $8 $9 $10 $11 $12

	return;
}

# 這是一個失敗的函式！存取參數時，一定要加上大括號 ({ }, Curly Brackets)，否則超過10以上的會有問題！

function curly()
{
	echo ${1} ${2} ${3} ${4} ${5} ${6} ${7} ${8} ${9} ${10} ${11} ${12}

	return;
}

# 這個函式才是正確的寫法！

echo $VAR1

echo $VAR2

# 若是存取非數值名稱的變數，有無加上大括號都無所謂！

non_brackets One Two Three Four Five Six Seven Eight Nine "Hey!! " "Hello!! " "World!! "

curly One Two Three Four Five Six Seven Eight Nine "Hey!! " "Hello!! " "World!! "

unset -v VAR1 VAR2

# 取消 (unset)變數 (Variable)的設定

unset -f non_brackets curly

# 取消 (unset)函式 (Function)的設定

set +x

# 相對於 "set -x" ，關閉所有的語法描述

exit 6

# 將這一個 Shell Script 的離開值設定成6；執行此 Shell Script 之後，再輸入 "echo $?" 可以確認

# 離開 Script 要用 exit；離開 Function 要用 return 
