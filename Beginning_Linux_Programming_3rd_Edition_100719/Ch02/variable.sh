#!/bin/bash

#
#	File Name: variable.sh
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
#	1. 等號 ('=')的兩邊不可以留有空白；
#	2. 在Shell Script中存取變數是用Dollar Sign '$'即可；GNU Make中則是$()
#	3. 為了確保$所指的變數為空字串，導致Shell Script出錯，最好在變數的前後都加上雙引號 ("")
#	4. 若只是要列印出變數的"名稱"而非"內容"，則是改用單引號 ('')，如'$myvar'
#	5. 承4. 或者是在$前面加上跳脫字元 (\)
#	6. Shell Script中的read指令很特別，可以儲存使用者所輸入的資料
#	7. NOTE!! 在使用read指令儲存變數時，變數前面不能加上$字號，因為加上$字號代表要讀取變數的內容
#

myvar="Hello!! World!! "

echo $myvar
echo "$myvar"
echo '$myvar'
echo \$myvar

echo "Enter some text: "
read myvar

echo '$myvar' now equals "$myvar"

exit 0
