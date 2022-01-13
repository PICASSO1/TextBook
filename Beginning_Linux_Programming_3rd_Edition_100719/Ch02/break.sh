#!/bin/bash

files=""

rm -vfR ./fred* 1> /dev/null 2>&1
echo 1> ./fred1
echo 1> ./fred2
mkdir -p ./fred3
echo 1> ./fred4

for files in ./fred*
do
	if [ -d "$files" ]; then
		break;
	fi
done

echo "First directory starting fred was $files"
rm -vfR ./fred* 2> /dev/null 1>&2

exit 0
