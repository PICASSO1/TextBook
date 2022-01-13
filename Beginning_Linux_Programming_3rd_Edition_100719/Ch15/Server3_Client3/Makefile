
GCC := gcc
CFLAGS := -o
OBJS := client3.o server3.o
EXEC := client3 server3
RM := rm -rf

.PHONY: all
all: $(EXEC)

$(EXEC): $(OBJS)
	@-$(GCC) $(CFLAGS) client3 client3.o
	@-$(GCC) $(CFLAGS) server3 server3.o

#client3.o: client3.c 
#	$(GCC) -c client3.c $(CFLAGS) client3.o
#server3.o: server3.c 
#	$(GCC) -c server3.c $(CFLAGS) server3.o
$(OBJS): %.o: %.c 
	@-$(GCC) -c $< $(CFLAGS) $@

.PHONY: clean cleanall install print tar dist TAGS check test
clean:
	@-$(RM) *.o

cleanall: clean
	@-$(RM) $(EXEC) server_socket

install:

print:

tar:

dist:

TAGS:

check: 

test:
