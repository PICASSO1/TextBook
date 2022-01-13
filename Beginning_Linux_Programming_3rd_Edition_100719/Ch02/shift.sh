#!/bin/bash

# Shift的用法：每執行一次Shift，$2會變成$1, $3會變成$2, $4會變成$3....依此類推！！

while [ "$1" != "" ]; do
	echo $1
	shift
done

exit 0
