
GCC := gcc
CFLAGS := -o
OBJS := client.o server.o
EXEC := client server
RM := rm -rf

.PHONY: all
all: $(EXEC)

$(EXEC): $(OBJS)
	@-$(GCC) $(CFLAGS) client client.o
	@-$(GCC) $(CFLAGS) server server.o

#client.o: client.c 
#	$(GCC) -c client.c $(CFLAGS) client.o
#server.o: server.c 
#	$(GCC) -c server.c $(CFLAGS) server.o
$(OBJS): %.o: %.c include.h define.h declare.h
	@-$(GCC) -c $< $(CFLAGS) $@

.PHONY: clean cleanall install print tar dist TAGS check test
clean:
	@-$(RM) *.o

cleanall: clean
	@-$(RM) $(EXEC) client.file

install:

print:

tar:

dist:

TAGS:

check: 

test:
