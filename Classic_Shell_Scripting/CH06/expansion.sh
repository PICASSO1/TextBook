####
 # File Name: expansion.sh
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

VAR="Hello!! World!! "

echo -en "\${VAR}:" \ \ \ \ \ \ \ ${VAR} "\n\n"

unset VAR

#################################################

# 若變數 VAR 沒有宣告或定義，則回傳 "ABCDE" 
echo "\${VAR:-ABCDE}:" ${VAR:-ABCDE}
echo "\${VAR}:" ${VAR}

echo -en "\n" && unset VAR

#################################################

# 若變數 VAR 沒有宣告或定義，則回傳 "ABCDE" 且將 VAR 設定成 "ABCDE" 
echo "\${VAR:=ABCDE}:" ${VAR:=ABCDE}
echo "\${VAR}:" \ \ \ \ \ \ \ ${VAR}

echo -en "\n" && unset VAR

#################################################

# 若變數 VAR 沒有宣告或定義，則輸出 "ABCDE" 且離開此 Shell Script
# 此一功能為驗證變數是否有宣告或定義；若問號 ('?')之後沒有任何輸入，預設字串為：
# "parameter null or not set"
# echo "\${VAR:?ABCDE}:" ${VAR:?ABCDE}

# echo -en "\n" && unset VAR

#################################################

# 若變數 VAR 沒有宣告或定義，則回傳 1 (失敗)，但不會離開此 Shell Script
# 此一功能為驗證變數是否有宣告或定義；與上一個範例 '?' 類似；但回傳值為 boolean 值
echo "\${VAR:+1}:" ${VAR:+1}
echo "\${VAR}:" \ \ \ \ \ \ \ ${VAR}

echo -en "\n" && unset VAR

#################################################

# 把上述四個範例的冒號 (':')移除，條件判斷變成「是否宣告，否則....」

#################################################

# 若變數 VAR 沒有宣告，則輸出 "ABCDE"
echo "\${VAR-ABCDE}:" ${VAR-ABCDE}
VAR=
echo "\${VAR-ABCDE}:" ${VAR-ABCDE}

echo -en "\n" && unset VAR

#################################################

# 若變數 VAR 沒有宣告，則輸出 "ABCDE" 且將 VAR 設定成 "ABCDE" 
echo "\${VAR=ABCDE}:" ${VAR=ABCDE}
VAR=
echo "\${VAR=ABCDE}:" ${VAR=ABCDE}

echo -en "\n" && unset VAR

#################################################

# 若變數 VAR 沒有宣告，則輸出問號 ('?')之後的字串，且離開此 Shell Script
# 此一功能為驗證變數是否有宣告；若問號 ('?')之後沒有任何輸入，預設字串為：
# "parameter not set"
# echo "\${VAR?}:" ${VAR?}

# echo -en "\n" && unset VAR

#################################################

# 若變數 VAR 沒有宣告，則回傳 0 (成功)，但不會離開此 Shell Script
# 此一功能為驗證變數是否有宣告或定義；與上一個範例 '?' 類似；但回傳值為 boolean 值
echo "\${VAR+0}:" ${VAR+0}
VAR=
echo "\${VAR+0}:" \ \ \ \ \ \ \ ${VAR+0}

echo -en "\n" && unset VAR
