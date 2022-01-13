
GCC := gcc
OBJS := user.o
EXEC := user
RM := /bin/rm -rf

obj-m := devone.o

INSMOD := /sbin/insmod
RMMOD := /sbin/rmmod

MKNOD := /bin/mknod

DEV0 := /dev/devone0
DEV1 := /dev/devone1
DEV2 := /dev/devone2
DEV3 := /dev/devone3
DEV4 := /dev/devone4

.PHONY: all
all: $(obj-m) $(EXEC) install

$(obj-m):
	# build Kernel Object Module (*.ko)
	make -C /lib/modules/$(shell uname -r)/build M=$(shell pwd) V=1 modules

$(EXEC): $(OBJS)
	# build User Executable File and Objects
	@-$(GCC) -o $(EXEC) $(OBJS)	

#$(OBJS):
#	$(GCC) -c main.c -o $(OBJS)
$(OBJS): %.o: %.c include.h define.h declare.h
	@-$(GCC) -c $< -o $@

install:
	@-$(INSMOD) devone.ko
	@-$(MKNOD) $(DEV0) c 250 0
	@-$(MKNOD) $(DEV1) c 250 1
	@-$(MKNOD) $(DEV2) c 250 2
	@-$(MKNOD) $(DEV3) c 250 3
	@-$(MKNOD) $(DEV4) c 250 4

.PHONY: clean cleanall print tar dist TAGS check test
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(shell pwd) clean
	@-$(RM) *.o

cleanall: clean
	@-$(RM) /dev/devone*
	@-$(RMMOD) devone.ko
	@-$(RM) $(EXEC)

print:

tar:

dist:

TAGS:

check: 

test:
