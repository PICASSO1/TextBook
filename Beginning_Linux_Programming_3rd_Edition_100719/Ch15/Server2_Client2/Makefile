
GCC := gcc
CFLAGS := -o
OBJS := client2.o server2.o
EXEC := client2 server2
RM := rm -rf

.PHONY: all
all: $(EXEC)

$(EXEC): $(OBJS)
	@-$(GCC) $(CFLAGS) client2 client2.o
	@-$(GCC) $(CFLAGS) server2 server2.o

#client2.o: client2.c 
#	$(GCC) -c client2.c $(CFLAGS) client2.o
#server2.o: server2.c 
#	$(GCC) -c server2.c $(CFLAGS) server2.o
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
