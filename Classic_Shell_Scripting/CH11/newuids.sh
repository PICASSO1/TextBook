#!/bin/bash - 

# newuids --- 列印一個或多個未使用的 uid
# 
# 語法：
#       newuids [-c N] list-of-ids-file
#       -c N 	印出 N 個未使用的 uid 

count=1    # 預定要印出的 uid 個數

# 剖析引數，令 sh 發出診斷
# 必要時離開程式

while getopts "c:" opt; do
	case ${opt} in 
		c)
			count=${OPTARG}
			;;
	esac
done

shift $((${OPTIND} - 1))

IDFILE=${1}

awk -v count=${count} '
	BEGIN {
		for (i = 1; getline id > 0; i++)
			uidlist[i] = id

		totalids = i

		for (i = 2; i <= totalids; i++) {
			if (uidlist[i - 1] != uidlist[i]) {
				for (j = uidlist[i - 1] + 1; j < uidlist[i]; j++) {
					print j
					if (--count == 0)
						exit
				}
			}
		}
	}' ${IDFILE}
