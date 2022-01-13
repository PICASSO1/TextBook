
GCC := gcc
CFLAGS := -c -g -DDEBUG
OBJS := source0.o source1.o
EXEC := source0 source1
RM := rm -rf

.PHONY: all
all: $(EXEC)

source0: source0.o
	@-$(GCC) -o source0 source0.o

source1: source1.o
	@-$(GCC) -o source1 source1.o

$(OBJS): %.o: %.c
	@-$(GCC) $(CFLAGS) $< -o $@

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
