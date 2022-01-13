
GCC := gcc
CFLAGS := -o
OBJS := client1.o server1.o
EXEC := client1 server1
RM := rm -rf

.PHONY: all
all: $(EXEC)

$(EXEC): $(OBJS)
	@-$(GCC) $(CFLAGS) client1 client1.o
	@-$(GCC) $(CFLAGS) server1 server1.o

#client1.o: client1.c 
#	$(GCC) -c client1.c $(CFLAGS) client1.o
#server1.o: server1.c 
#	$(GCC) -c server1.c $(CFLAGS) server1.o
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
