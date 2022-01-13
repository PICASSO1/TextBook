
GCC := gcc
SOURCE := main.c
CFLAGS := -c -g -DDEBUG -Wall -pedantic -O2
#INCLUDE := 
#LIB := 
#LINK := 
OBJS := main.o
EXEC := main
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
