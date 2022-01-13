
GCC := gcc
LDFLAGS += -Map $(PWD)/example.map
RM := /bin/rm -rf

obj-m := example.o

INSMOD := /sbin/insmod
RMMOD := /sbin/rmmod

.PHONY: all
all: $(obj-m) install

$(obj-m): 
	# build Kernel Object Module (*.ko)
	make -C /lib/modules/$(shell uname -r)/build M=$(shell pwd) V=1 modules

install:
	@-$(INSMOD) example.ko

.PHONY: clean cleanall print tar dist TAGS check test
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(shell pwd) clean

cleanall: clean
	@-$(RMMOD) example.ko
	@-$(RM) example.map

print:

tar:

dist:

TAGS:

check: 

test:
