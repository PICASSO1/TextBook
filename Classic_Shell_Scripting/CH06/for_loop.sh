####
 # File Name: arguments.sh
 #
 # CopyLeft (C) 2023, Picasso's Fantasy Notepad. All rights reserved.
 #
 # Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 #
 # Version: 1.0.0.build080723
 #
 # Date: 2023 / 08 / 07
 #
 # Description: 這個範例很無聊，只不過是在介紹在 Shell Script 裡的 break & continue 後面都可以再接上參數；若無，預設值為1。
 #
######

#!/bin/bash - 

X=""
Y=""
Z=""

for X in $(seq 0 1 5); do
	for Y in $(seq 0 1 7); do
		for Z in $(seq 0 1 9); do
			[ "$Z" -eq 3 ] && break 2;
			printf "XYZ[%d][%d][%d] \n" ${X} ${Y} ${Z}
		done
		echo -en "\n"
	done
	echo -en "\n\n"
done

echo "#############################################"

for X in $(seq 0 1 5); do
	for Y in $(seq 0 1 7); do
		for Z in $(seq 0 1 9); do
			[ "$Z" -eq 6 ] && continue 2;
			printf "XYZ[%d][%d][%d] \n" ${X} ${Y} ${Z}
		done
		echo -en "\n"
	done
	echo -en "\n\n"
done

exit 0;
