
CFILES := main.c sub.c

obj-m := hello.o

hello-objs := $(CFILES:.c=.o)

.PHONY: all
all:
	make -C /lib/modules/$(shell uname -r)/build M=$(shell pwd) V=1 modules

.PHONY: clean install print tar dist TAGS check test
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(shell pwd) clean

install:

print:

tar:

dist:

TAGS:

check: 

test:
