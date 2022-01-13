
GCC := gcc
OBJS := user.o
EXEC := user
RM := /bin/rm -rf

obj-m := example.o

INSMOD := /sbin/insmod
RMMOD := /sbin/rmmod

MKNOD := /bin/mknod

DEV0 := /dev/example0
DEV1 := /dev/example1
DEV2 := /dev/example2
DEV3 := /dev/example3

.PHONY: all
all: $(obj-m) $(EXEC) install

$(obj-m): example.h
	# build Kernel Object Module (*.ko)
	make -C /lib/modules/$(shell uname -r)/build M=$(shell pwd) V=1 modules

$(EXEC): $(OBJS)
	# build User Executable File and Objects
	@-$(GCC) -o $(EXEC) $(OBJS)

#$(OBJS):
#	$(GCC) -c main.c -o $(OBJS)
$(OBJS): %.o: %.c user.h
	@-$(GCC) -c $< -o $@

install:
	@-$(INSMOD) example.ko
	@-$(MKNOD) $(DEV0) c 250 6
	@-$(MKNOD) $(DEV1) c 250 7
	@-$(MKNOD) $(DEV2) c 250 8
	@-$(MKNOD) $(DEV3) c 250 9

.PHONY: clean cleanall print tar dist TAGS check test
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(shell pwd) clean
	@-$(RM) *.o

cleanall: clean
	@-$(RM) /dev/example*
	@-$(RMMOD) example.ko
	@-$(RM) $(EXEC)

print:

tar:

dist:

TAGS:

check: 

test:
