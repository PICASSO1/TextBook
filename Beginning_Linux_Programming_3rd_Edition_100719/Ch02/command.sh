#!/bin/bash

rm -vf ./fred 2> /dev/null 1>&2

if [ -f "fred" ]; then
	:
else
	echo -en "File \"fred\" didn't exit!! \n"
fi

exit 0
