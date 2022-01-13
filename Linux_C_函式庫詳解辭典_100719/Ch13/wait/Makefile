
GCC := gcc
CFLAGS := -o
OBJS := wait.o wait2.o Hello.o World.o
EXEC := wait wait2 Hello World
RM := rm -rf

.PHONY: all
all: wait wait2 Hello World

wait:
	@-$(GCC) -c wait.c $(CFLAGS) wait.o
	@-$(GCC) $(CFLAGS) wait wait.o
wait2:
	@-$(GCC) -c wait2.c $(CFLAGS) wait2.o
	@-$(GCC) $(CFLAGS) wait2 wait2.o
Hello:
	@-$(GCC) -c Hello.c $(CFLAGS) Hello.o
	@-$(GCC) $(CFLAGS) Hello Hello.o
World:
	@-$(GCC) -c World.c $(CFLAGS) World.o
	@-$(GCC) $(CFLAGS) World World.o

.PHONY: clean cleanall install print tar dist TAGS check test
clean:
	@-$(RM) *.o

cleanall: clean
	@-$(RM) $(EXEC)

install:

print:

tar:

dist:

TAGS:

check: 

test:
