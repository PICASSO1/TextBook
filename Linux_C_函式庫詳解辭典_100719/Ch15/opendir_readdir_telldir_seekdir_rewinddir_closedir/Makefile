
GCC := gcc
CFLAGS := -o
OBJS := main.o
EXEC := main
RM := rm -rf

.PHONY: all
all: $(EXEC)

$(EXEC): $(OBJS)
	@-$(GCC) $(CFLAGS) $(EXEC) $(OBJS)
	@-$(shell mkdir -p TEST; )
	@-$(shell touch ./TEST/1.TXT ./TEST/2.TXT ./TEST/3.TXT ./TEST/4.TXT ./TEST/5.TXT; )
	
#$(OBJS):
#	$(GCC) -c main.c $(CFLAGS) $(OBJS)
$(OBJS): %.o: %.c
	@-$(GCC) -c $< $(CFLAGS) $@

.PHONY: clean cleanall install print tar dist TAGS check test
clean:
	@-$(RM) *.o

cleanall: clean
	@-$(RM) $(EXEC)
	@-rm -vfR ./TEST 2> /dev/null 1>&2

install:

print:

tar:

dist:

TAGS:

check: 

test:
