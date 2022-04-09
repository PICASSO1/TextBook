
GCC := gcc
CFLAGS := -o
OBJS := main.o
EXEC := main
RM := rm -rf

.PHONY: all
all: $(EXEC)

$(EXEC): $(OBJS)
	@-$(GCC) $(CFLAGS) $(EXEC) $(OBJS)

$(OBJS): %.o: %.c
	@-$(GCC) -c $< $(CFLAGS) $@

.PHONY: clean cleanall install print tar dist TAGS check test
clean:
	@-$(RM) *.o *.S

cleanall: clean
	@-$(RM) $(EXEC) 

install:

print:

tar:

dist:

TAGS:

check: 

test:
