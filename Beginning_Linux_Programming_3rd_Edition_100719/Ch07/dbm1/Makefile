
GCC := gcc
CFLAGS := -c

# For GNU GDB debug
CFLAGS +=  -g -DDEBUG

#To show the ALL Warning messages
#CFLAGS += -Wall -pedantic -ansi

# Optimization
CFLAGS += -O

OBJS := dbm1.o
EXEC := dbm1
RM := rm -rf
INCLUDE := /usr/local/include/
LIB := gdbm
LIBS := /usr/local/lib/

.PHONY: all
all: $(EXEC)

$(EXEC): $(OBJS)
	@-$(GCC) -o $(EXEC) $(OBJS) -I$(INCLUDE) -L$(LIBS) -l$(LIB)
	
$(OBJS): %.o: %.c
	@-$(GCC) $(CFLAGS) $< -o $@

.PHONY: clean cleanall install print tar dist TAGS check test
clean:
	@-$(RM) *.o /tmp/dbm1_test.* 2> /dev/null 1>&2

cleanall: clean
	@-$(RM) $(EXEC)

install:

print:

tar:

dist:

TAGS:

check: 

test:
