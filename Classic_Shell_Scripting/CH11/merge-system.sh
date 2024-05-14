#!/bin/bash - 

sort u1.passwd u2.passwd 1> merge1

awk -f splitout.awk merge1

awk -F: '{print ${3}}' merge1 | sort -n -u 1> unique-ids

rm -f old-new-list

old_ifs=${IFS}
IFS=':'
while read user passwd uid gid fullname homedir shell; do
	if read user2 passwd2 uid2 gid2 fullname2 homedir2 shell2; then
		if [ ${user} = ${user2} ]; then
			printf "%s\t%s\t%s\n" ${user} ${uid} ${uid2} 1>> old-new-list
			echo "${user}:${passwd}:${uid}:${gid}:${fullname}:${homedir}:${shell}"
		else
			echo ${0}: out of sync: ${user} and ${user2} 1>&2
			exit 1
		fi
	else
		echo ${0}: no duplicate for ${user} 1>&2
		exit 1
	fi
done < dupusers > unique2

IFS=${old_ifs}

count=$(wc -l 0< dupids)    # 計算重複的 id 數目

# 若 POSIX sh 有陣列，請這用：
set -- $(newuids.sh -c ${count} unique-ids)

IFS=':'
while read user passwd uid gid fullname homedir shell; do
	newuid=${1}
	shift
	echo "${user}:${passwd}:${uid}:${gid}:${fullname}:${homedir}:${shell}"
	printf "%s\t%s\t%s\n" ${user} ${uid} ${newuid} 1>> old-new-list
done < dupids > unique3

IFS=${old_ifs}

sort -k 3 -t : -n unique[123] 1> final.password

while read user old new; do
	echo "find / -user ${user} -print | xargs chown ${new}"
done < old-new-list > chown-files

chmod -x chown-files

rm merge1 unique[123] dupusers dupids unique-ids old-new-list
