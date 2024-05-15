#!/bin/bash - 

# 
# 持續地執行 ps 指令，每次顯示之間，只做短時間的暫停。
# 
# 語法：simple-top.sh
# 

IFS='
        '

# 自訂 PATH ，以先取得 BSD 式的 ps
PATH=/usr/ucb:/usr/bin:/bin
export PATH

HEADFLAGS="-n 20"
PSFLAGS="aux"
SLEEPFLAGS=5
SORTFLAGS="-k3nr -k1,1 -k2n"

HEADER="`ps ${PSFLAGS} | head -n 1`"

while true; do
	clear
	uptime
	echo ${HEADER}
	ps ${PSFLAGS} | sed -e 1d | sort ${SORTFLAGS} | head ${HEADFLAGS}
	sleep ${SLEEPFLAGS}
done
