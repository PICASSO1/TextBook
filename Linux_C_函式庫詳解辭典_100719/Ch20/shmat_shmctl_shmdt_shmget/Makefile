
GCC := gcc
CFLAGS := -o
OBJS := main0.o main1.o
EXEC := main0 main1
RM := rm -rf

.PHONY: all
all: $(EXEC)

main0: main0.o
	@-$(GCC) -c main0.c $(CFLAGS) main0.o
	@-$(GCC) $(CFLAGS) main0 main0.o

main1: main1.o
	@-$(GCC) -c main1.c $(CFLAGS) main1.o
	@-$(GCC) $(CFLAGS) main1 main1.o

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
