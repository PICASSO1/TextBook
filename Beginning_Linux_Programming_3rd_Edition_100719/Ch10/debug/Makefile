
GCC := gcc
CFLAGS := -c -g -DDEBUG
CFLAGS += -Wall -pedantic -ansi -O
OBJS := debug.o
EXEC := debug
RM := rm -rf

.PHONY: all
all: $(EXEC)

$(EXEC): $(OBJS)
	@-$(GCC) -o $(EXEC) $(OBJS)
	
#$(OBJS):
#	$(GCC) -c main.c $(CFLAGS) $(OBJS)
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
