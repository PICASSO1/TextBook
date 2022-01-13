
GCC := gcc
CFLAGS := -c

# For GNU GDB debug
CFLAGS +=  -g -DDEBUG

#To show the ALL Warning messages
#CFLAGS += -Wall -pedantic -ansi

# Optimization
CFLAGS += -O

OBJS := pad.o
EXEC := pad
RM := rm -rf
DEPS := /usr/include/ncurses/
LIBS := ncurses
LDIR := /usr/lib/

.PHONY: all
all: $(EXEC)

$(EXEC): $(OBJS)
	@-$(GCC) -o $(EXEC) $(OBJS) -I$(DEPS) -L$(LDIR) -l$(LIBS)
	
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
