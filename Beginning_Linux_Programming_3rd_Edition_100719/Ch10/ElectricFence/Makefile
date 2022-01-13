
GCC := gcc
CFLAGS := -o
OBJS := efence.o
EXEC := efence
RM := rm -rf

.PHONY: all
all:
	@-$(GCC) $(CFLAGS) $(EXEC) efence.c -lefence.a

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
