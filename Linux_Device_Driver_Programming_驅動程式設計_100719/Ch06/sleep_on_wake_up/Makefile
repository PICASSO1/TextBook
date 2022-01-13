
GCC := gcc
OBJS := user.o
EXEC := user
RM := /bin/rm -rf

obj-m := sleepon.o wakeup.o

INSMOD := /sbin/insmod
RMMOD := /sbin/rmmod

MKNOD := /bin/mknod

DEV := /dev/sleepon

.PHONY: all
all: $(obj-m) $(EXEC) install

$(obj-m): devone.h
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
	@-$(INSMOD) sleepon.ko
#	@-$(INSMOD) wakeup.ko
	@-$(MKNOD) $(DEV) c 249 0

.PHONY: clean cleanall print tar dist TAGS check test
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(shell pwd) clean
	@-$(RM) *.o

cleanall: clean
	@-$(RM) $(DEV)
	@-$(RMMOD) sleepon.ko wakeup.ko
	@-$(RM) $(EXEC)

print:

tar:

dist:

TAGS:

check: 

test:
