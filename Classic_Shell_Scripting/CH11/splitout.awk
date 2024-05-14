#!/bin/awk -f 

# $1      $2$3   $4   $5         $6            $7
# picasso:x:1000:1000:picasso,,,:/home/picasso:/bin/bash

BEGIN {FS = ":"}

# name[] ---- 以 username 為索引
# uid[]  ---- 以 uid 為索引

# 若出現重複，決定其配置

{
	if (${1} in name) {
		if (${3} in uid)
			;                            # 名稱與 uid 一致，啥事都不做
		else {
			print name[${1}] 1> "dupusers"
			print ${0} 1> "dupusers"
			delete name[${1}]
			# 移除名稱相同，uid 不同的已儲存項目
			remove_uid_by_name(${1})
		}
	}
	else if (${3} in uid) {
		# 知道 ${1} 並不在名稱 name 裡，所以儲存重複的 ID 紀錄
		print uid[${3}] 1> "dupids"
		print ${0} 1> "dupids"
		delete uid[${3}]
		# 移除具有相同 uid ，不同名稱的的已儲存項目
		remove_name_by_uid(${3})
	}
	else
		name[${1}] = uid[${3}] = ${0}    # 第一次看到這乙筆紀錄
}

END {
	for (i in name)
		print name[i] 1> "uniquel"

	close("uniquel")
	close("dupusers")
	close("dupids")
}

function remove_uid_by_name(n, i, f)
{
	for (i in uid) {
		split(uid[i], f, ":")
		if (f[1] == n) {
			delete uid[i]
			break
		}
	}
}

function remove_name_by_uid(id, i, f)
{
	for (i in name) {
		split(name[i], f, ":")
		if (f[3] == id) {
			delete name[i]
			break
		}
	}
}
