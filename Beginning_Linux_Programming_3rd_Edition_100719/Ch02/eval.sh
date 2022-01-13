#!/bin/bash

y=0
foo=10
x=foo

eval y='$'$x
echo -en "\$y = $y \n"

exit 0
