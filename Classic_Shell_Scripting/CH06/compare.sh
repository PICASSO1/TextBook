####
 # File Name: compare.sh
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

VAR="ABCDEABCDEABCDEVWXYZVWXYZVWXYZ"

printf "\${VAR}:       %s (%d) \n" ${VAR} ${#VAR}

# VAR 變數當中，前面有符合 "ABCDE" 的部份移除
echo "\${VAR#ABCDE}: "${VAR#ABCDE}

# VAR 變數當中，前面有符合 "A*E" 的部份全部移除
echo "\${VAR##A*E}:  "${VAR##A*E}

# VAR 變數當中，後面有符合 "VWXYZ" 的部份移除
echo "\${VAR%VWXYZ}: "${VAR%VWXYZ}

# VAR 變數當中，後面有符合 "V*Z" 的部份全部移除
echo "\${VAR%%V*Z}:  "${VAR%%V*Z}

# VAR 變數當中，從第 11 個元素開始列印
echo "\${VAR:11}:    "${VAR:11}

# VAR 變數當中，從第 8 個元素開始，列印 20 個元素
echo "\${VAR:8:20}:  "${VAR:8:20}

exit 5
