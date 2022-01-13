#!/bin/bash

foo="The first meta-syntactic variable"
bar="The second meta-syntactic variable"
export bar

exec ./export1.sh

exit 0
