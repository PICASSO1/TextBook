#!/bin/bash

#
#	File Name: trap.sh
#
#	CopyLeft (C) 2016; All rights reserved.
#
#	Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
#
#	Version: 0.0.1.build021816
#
#	Date: 2016 / 02 / 18
#
#	Description: 
#	1. 這一個*.sh檔案，示範了Shell Script中trap命令的用法。
#	2. Shell Script中trap的概念，和C裡的signal()函式很類似，
#	3. "trap -l", "kill -l"可以查看系統中所支援的訊號 (signal)列表，
#	4. 如trap "rm -vf /tmp/my_tmp_file_$$ 2> /dev/null 1>&2" SIGINT
#	    當這一支script接收到SIGINT (中斷)的訊號時，就執行"rm -vf /tmp/my_tmp_file_$$ 2> /dev/null 1>&2"這一件事。
#

trap "rm -vf /tmp/my_tmp_file_$$ 2> /dev/null 1>&2" SIGINT
printf "Create the file: /tmp/my_tmp_file_%d \n" $$
date 1> /tmp/my_tmp_file_$$

printf "Press interrupt (Ctrl+C) to interrupt .... \n"
while [ -f /tmp/my_tmp_file_$$ ]; do
	printf "The file exit!! \n"
	sleep 1
done
printf "The file no longer exits. \n"

trap INT
printf "Creating the file: /tmp/my_tmp_file_%d \n" $$
date 1> /tmp/my_tmp_file_$$

printf "Press interrupt (Ctrl+C) to interrupt .... \n"
while [ -f /tmp/my_tmp_file_$$ ]; do
	printf "The file exit!! \n"
	sleep 1
done

printf "We never get here!! \n"

exit 0
