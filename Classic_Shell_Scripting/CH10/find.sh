#!/bin/bash - 

# 尋找所有的檔案及目錄，
# 在目錄樹下，將最近修改過的加以群組化，
# 並於最上層的 FILES.* 與 DIRECTORIES.* 內建清單。
# 
# 語法： filesdirectories directory 
# 

IFS='
        '

PATH=/usr/local/bin:/bin:/usr/bin    # 需要 GNU find 的 -fprint 選項
export PATH

if [ $# -ne 1 ]; then
	echo "Usage: ${0} directory" 1>&2
	exit 1
fi

umask 077                            # 確保檔案隱私
TMP=${TMPDIR:-/tmp}                     # 允許另一個暫時性目錄
TMPFILES="
	${TMP}/DIRECTORIES.all.$$ ${TMP}/DIRECTORIES.all.$$.tmp
	${TMP}/DIRECTORIES.last01.$$ ${TMP}/DIRECTORIES.last01.$$.tmp
	${TMP}/DIRECTORIES.last02.$$ ${TMP}/DIRECTORIES.last02.$$.tmp
	${TMP}/DIRECTORIES.last07.$$ ${TMP}/DIRECTORIES.last07.$$.tmp
	${TMP}/DIRECTORIES.last14.$$ ${TMP}/DIRECTORIES.last14.$$.tmp
	${TMP}/DIRECTORIES.last31.$$ ${TMP}/DIRECTORIES.last31.$$.tmp
	${TMP}/FILES.all.$$ ${TMP}/FILES.all.$$.tmp
	${TMP}/FILES.last01.$$ ${TMP}/FILES.last01.$$.tmp
	${TMP}/FILES.last02.$$ ${TMP}/FILES.last02.$$.tmp
	${TMP}/FILES.last07.$$ ${TMP}/FILES.last07.$$.tmp
	${TMP}/FILES.last14.$$ ${TMP}/FILES.last14.$$.tmp
	${TMP}/FILES.last31.$$ ${TMP}/FILES.last31.$$.tmp
	"

WD=${1}
cd ${WD} || exit 1
trap "exit 1"	HUP INT PIPE QUIT TERM
trap "rm -f ${TMPFILES}" EXIT

find . \
	-name DIRECTORIES.all -true \
	-o -name "DIRECTORIES.last[0-9][0-9]" -true \
	-o -name FILES.all -true \
	-o -name "FILES.last[0-9][0-9]" -true \
	-o -type f -fprint ${TMP}/FILES.all.$$ \
	-a -mtime -31 -fprint ${TMP}/FILES.last31.$$ \
	-a -mtime -14 -fprint ${TMP}/FILES.last14.$$ \
	-a -mtime -7 -fprint ${TMP}/FILES.last07.$$ \
	-a -mtime -2 -fprint ${TMP}/FILES.last02.$$ \
	-a -mtime -1 -fprint ${TMP}/FILES.last01.$$ \
	-o -type d -fprint ${TMP}/DIRECTORIES.all.$$ \
	-a -mtime -31 -fprint ${TMP}/DIRECTORIES.last31.$$ \
	-a -mtime -14 -fprint ${TMP}/DIRECTORIES.last14.$$ \
	-a -mtime -7 -fprint ${TMP}/DIRECTORIES.last07.$$ \
	-a -mtime -2 -fprint ${TMP}/DIRECTORIES.last02.$$ \
	-a -mtime -1 -fprint ${TMP}/DIRECTORIES.last01.$$

for i in FILES.all FILES.last31 FILES.last14 FILES.last07 FILES.last02 FILES.last01 \
	DIRECTORIES.all DIRECTORIES.last31 DIRECTORIES.last14 DIRECTORIES.last07 DIRECTORIES.last02 DIRECTORIES.last01; do
	sed -e "s=^[.]/=${WD}/=" -e "s=^[.]$=${WD}=" ${TMP}/$i.$$ | LC_ALL=C sort 1> ${TMP}/$i.$$.tmp
	cmp -s ${TMP}/$i.$$.tmp $i || mv ${TMP}/$i.$$.tmp $i
done
