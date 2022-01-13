#!/bin/bash

foo="Hello!! World!! "
printf "%s\n" $foo
unset foo
printf "%s\n" $foo

exit 0
