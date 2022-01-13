
GCC := gcc
SOURCES := pipe3.c pipe4.c

CFLAGS := -c
# For GNU GDB debug
CFLAGS += -g -DDEBUG
#To show the ALL Warning messages
CFLAGS +=  -Wall
#If the compiler (GCC) doesn't match with ANSI / ISO C99. this argument will show some error messages
CFLAGS += -pedantic
# Follow ANSI C standard
CFLAGS += -ansi
# Optimization
CFLAGS +=  -O2
# Define _REENTRANT for pthread....
#CFLAGS += -D_REENTRANT

#INCLUDE := /usr/include/nptl
#LIB := /usr/lib/nptl
#LINK := pthread
OBJS := pipe3.o pipe4.o
EXEC := pipe3 pipe4
RM := rm -rf

.PHONY: all
all: $(EXEC)

pipe3: pipe3.o
	@-$(GCC) -o pipe3 pipe3.o

pipe4: pipe4.o
	@-$(GCC) -o pipe4 pipe4.o

#$(EXEC): $(OBJS)
#	@-$(GCC) -o $(EXEC) $(OBJS)
	
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
