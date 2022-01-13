
GCC := gcc
CFLAGS := -o
OBJS := client4.o server4.o
EXEC := client4 server4
RM := rm -rf

.PHONY: all
all: $(EXEC)

$(EXEC): $(OBJS)
	@-$(GCC) $(CFLAGS) client4 client4.o
	@-$(GCC) $(CFLAGS) server4 server4.o

#client4.o: client4.c 
#	$(GCC) -c client4.c $(CFLAGS) client4.o
#server4.o: server4.c 
#	$(GCC) -c server4.c $(CFLAGS) server4.o
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
