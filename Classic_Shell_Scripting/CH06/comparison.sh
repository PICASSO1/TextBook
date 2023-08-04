####
 # File Name: comparison.sh
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
 #              1. 數值 (value) 的比較，請用：-eq, -ne, -gt, -ge, -lt, -le
 #              2. 字串 (string) 的比較，請用："=" or "!=" ；不要用 "==" Shell Script 並無此一語法。
 #
######

#!/bin/bash - 

# 若 VAR1 & VAR2 相等 (Equal)，則為真
VAR1="500"
VAR2="500"
[ "${VAR1}" -eq "${VAR2}" ] && {
	echo "1. The value \"$VAR1\" IS Equal to \"$VAR2\"!!"
} || {
	echo "1. The value \"$VAR1\" ISN'T Equal to \"$VAR2\"!!"
}

echo -en "\n"

##################################################

# 若 VAR1 & VAR2 不相等 (Not Equal)，則為真
VAR1="200"
VAR2="50"
[ "${VAR1}" -ne "${VAR2}" ] && {
	echo "2. The value \"$VAR1\" ISN'T Equal to \"$VAR2\"!!"
} || {
	echo "2. The value \"$VAR1\" IS Equal to \"$VAR2\"!!"
}

echo -en "\n"

##################################################

# 若 VAR1 小於 (Less Than) VAR2，則為真
VAR1="50"
VAR2="200"
[ "${VAR1}" -lt "${VAR2}" ] && {
	echo "3. The value \"$VAR1\" IS Less Than \"$VAR2\"!!"
} || {
	echo "3. The value \"$VAR1\" ISN'T Less Than \"$VAR2\"!!"
}

echo -en "\n"

##################################################

# 若 VAR1 小於等於 (Less & Equal) VAR2，則為真
VAR1="200"
VAR2="200"
[ "${VAR1}" -le "${VAR2}" ] && {
	echo "4. The value \"$VAR1\" IS Less & Equal \"$VAR2\"!!"
} || {
	echo "4. The value \"$VAR1\" ISN'T Less & Equal \"$VAR2\"!!"
}

echo -en "\n"

##################################################

# 若 VAR1 大於 (Greater Than) VAR2，則為真
VAR1="200"
VAR2="20"
[ "${VAR1}" -gt "${VAR2}" ] && {
	echo "5. The value \"$VAR1\" IS Greater Than \"$VAR2\"!!"
} || {
	echo "5. The value \"$VAR1\" ISN'T Greater Than \"$VAR2\"!!"
}

echo -en "\n"

##################################################

# 若 VAR1 大於等於 (Greater & Equal) VAR2，則為真
VAR1="500"
VAR2="500"
[ "${VAR1}" -ge "${VAR2}" ] && {
	echo "6. The value \"$VAR1\" IS Greater & Equal \"$VAR2\"!!"
} || {
	echo "6. The value \"$VAR1\" ISN'T Greater & Equal \"$VAR2\"!!"
}

echo -en "\n"

##################################################

# 若字串 VAR1 & VAR2 不相等 (!=)，則為真
VAR1="Hello!! World!! "
VAR2=""
[ "${VAR1}" != "${VAR2}" ] && {
	echo "7. The string \"$VAR1\" ISN'T Equal with \"$VAR2\"!!"
} || {
	echo "7. The string \"$VAR1\" IS Equal with \"$VAR2\"!!"
}

echo -en "\n"

##################################################

# 若字串 VAR1 & VAR2 相等 (=)，則為真
VAR1="Hello!! World!! "
VAR2="Hello!! World!! "
[ "${VAR1}" = "${VAR2}" ] && {
	echo "8. The string \"$VAR1\" IS Equal with \"$VAR2\"!!"
} || {
	echo "8. The string \"$VAR1\" ISN'T Equal with \"$VAR2\"!!"
}

echo -en "\n"
