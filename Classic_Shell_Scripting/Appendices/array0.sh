####
 # File Name: array0.sh
 #
 # CopyLeft (C) 2023, Picasso's Fantasy Notepad. All rights reserved.
 #
 # Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 #
 # Version: 1.0.0.build083023
 #
 # Date: 2023 / 08 / 30
 #
 # Description: 
 #              1. Shell Script 中陣列 (Array)的基本應用。
 #              2. 注意！Shell Script 並不支援二維陣列！
 #
######

#!/bin/bash - 

idx=0
LEN=0

# 陣列的定義方法I：用逗號 (',')區別每一個元素
array0=(1, 2, 3, 4, 5, 6)
array1=('A', 'B', 'C', 'D', 'E', 'F')
array2=("Hello!! ", "How ", "are ", "you?? ")

# 陣列的定義方法II：個別地指定元素
array3[0]=7
array3[1]=8
array3[2]=9
array3[3]=0

array4[0]='G'
array4[1]='H'
array4[2]='I'
array4[3]='J'

array5[0]="How "
array5[1]="do "
array5[2]="you "
array5[3]="do?? "

# 陣列的定義方法III：類似方法I；但改用空格 (' ')來區別每一個元素
array6=(11 12 13 14 15)
array7=('k' 'l' 'm' 'n' 'o')
array8=("I'm " "fine, " "thanks! " "And you? ")

# 計算陣列長度的方式：
echo "The length of ayyay0 is: " "${#array0[@]}"
echo "The length of ayyay1 is: " "${#array1[*]}"
echo "The length of ayyay2 is: " "${#array2[@]}"
echo "The length of ayyay3 is: " "${#array3[*]}"
echo "The length of ayyay4 is: " "${#array4[@]}"
echo "The length of ayyay5 is: " "${#array5[*]}"
echo "The length of ayyay6 is: " "${#array6[@]}"
echo "The length of ayyay7 is: " "${#array7[*]}"
echo "The length of ayyay8 is: " "${#array8[@]}"

echo -en "\n"

# 呈現陣列內容的方式：留意 array0, array1, array2, array8 會自動地加上空格 (' ')
echo "\${array0[@]}:" "${array0[@]}"
echo "\${array1[*]}:" "${array1[*]}"
echo "\${array2[@]}:" "${array2[@]}"
echo "\${array3[@]}:" "${array3[@]}"
echo "\${array4[*]}:" "${array4[*]}"
echo "\${array5[*]}:" "${array5[*]}"
echo "\${array6[@]}:" "${array6[@]}"
echo "\${array7[*]}:" "${array7[*]}"
echo "\${array8[@]}:" "${array8[@]}"

echo -en "\n"

# 依序地取出陣列裡的每一個元素

LEN="${#array0[@]}"

for ((idx = 0; idx < LEN; idx++)); do
	echo "\${array0["$idx"]}:" "${array0["$idx"]}"
done

echo -en "\n"

###################################

LEN="${#array1[*]}"

for ((idx = 0; idx < LEN; idx++)); do
	echo "\${array1["$idx"]}:" "${array1["$idx"]}"
done

echo -en "\n"

###################################

LEN="${#array2[@]}"

for ((idx = 0; idx < LEN; idx++)); do
	echo "\${array2["$idx"]}:" "${array2["$idx"]}"
done

echo -en "\n"

###################################

LEN="${#array3[@]}"

for ((idx = 0; idx < LEN; idx++)); do
	echo "\${array3["$idx"]}:" "${array3["$idx"]}"
done

echo -en "\n"

###################################

LEN="${#array4[*]}"

for ((idx = 0; idx < LEN; idx++)); do
	echo "\${array4["$idx"]}:" "${array4["$idx"]}"
done

echo -en "\n"

###################################

LEN="${#array5[*]}"

for ((idx = 0; idx < LEN; idx++)); do
	echo "\${array5["$idx"]}:" "${array5["$idx"]}"
done

echo -en "\n"

###################################

LEN="${#array6[@]}"

for ((idx = 0; idx < LEN; idx++)); do
	echo "\${array6["$idx"]}:" "${array6["$idx"]}"
done

echo -en "\n"

###################################

LEN="${#array7[*]}"

for ((idx = 0; idx < LEN; idx++)); do
	echo "\${array7["$idx"]}:" "${array7["$idx"]}"
done

echo -en "\n"

###################################

LEN="${#array8[@]}"

for ((idx = 0; idx < LEN; idx++)); do
	echo "\${array8["$idx"]}:" "${array8["$idx"]}"
done

echo -en "\n"
