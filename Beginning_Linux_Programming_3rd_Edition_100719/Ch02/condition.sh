#!/bin/bash

if [ -f /bin/bash ]; then
	echo "The file: /bin/bash exits!! "
fi

if [ -d /bin/bash ]; then
	echo "/bin/bash is a directory!! "
else
	echo "/bin/bash is NOT a directory!! "
fi

exit 0
