
GCC := gcc
CFLAGS := -o
OBJS := client5.o server5.o
EXEC := client5 server5
RM := rm -rf

.PHONY: all
all: $(EXEC)

$(EXEC): $(OBJS)
	@-$(GCC) $(CFLAGS) client5 client5.o
	@-$(GCC) $(CFLAGS) server5 server5.o

#client3.o: client3.c 
#	$(GCC) -c client5.c $(CFLAGS) client5.o
#server3.o: server3.c 
#	$(GCC) -c server5.c $(CFLAGS) server5.o
$(OBJS): %.o: %.c 
	@-$(GCC) -c $< $(CFLAGS) $@

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
