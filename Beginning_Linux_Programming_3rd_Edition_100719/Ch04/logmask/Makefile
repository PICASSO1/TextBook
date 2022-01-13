
GCC := gcc
CFLAGS := -c

# For GNU GDB debug
CFLAGS +=  -g -DDEBUG

#To show the ALL Warning messages
#CFLAGS += -Wall -pedantic -ansi

# Optimization
CFLAGS += -O

OBJS := logmask.o
EXEC := logmask
RM := rm -rf

.PHONY: all
all: $(EXEC)

$(EXEC): $(OBJS)
	@-$(GCC) -o $(EXEC) $(OBJS)
	
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
