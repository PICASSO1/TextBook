#!/bin/bash

files=""

rm -vfR ./fred* 1> /dev/null 2>&1
echo 1> ./fred1
echo 1> ./fred2
mkdir -p ./fred3
echo 1> ./fred4

for files in fred*; do
	if [ -d "$files" ]; then
		echo -en "Skipping directory $files \n"
		continue
	fi
	echo -en "The file is: $files \n"
done

rm -vfR ./fred* 2> /dev/null 1>&2

exit 0
