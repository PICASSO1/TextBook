#!/bin/bash

x=0

for x in 1 2 3; do
	echo -en "Before $x \n"
	continue 1
	echo -en "After $x \n"
done

exit 0
