
GCC := gcc
CFLAGS := -o
OBJS := main.o
EXEC := main
RM := rm -rf

.PHONY: all
all: $(EXEC)

$(EXEC): $(OBJS)
	@-$(GCC) $(CFLAGS) $(EXEC) $(OBJS)
	
#$(OBJS):
#	$(GCC) -c main.c $(CFLAGS) $(OBJS)
$(OBJS): %.o: %.c
	@-$(GCC) -c $< $(CFLAGS) $@

.PHONY: clean cleanall install print tar dist TAGS check test
clean:
	@-$(RM) *.o TEST.INI  2> /dev/null 1>&2

cleanall: clean
	@-$(RM) $(EXEC) hello.info 1> /dev/null 2>&1

install:

print:

tar:

dist:

TAGS:

check: 

test:
