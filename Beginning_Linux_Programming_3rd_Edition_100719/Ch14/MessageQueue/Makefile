
GCC := gcc
CFLAGS := -o
OBJS := msg1.o msg2.o
EXEC := msg1 msg2
RM := rm -rf

.PHONY: all
all: $(EXEC)

$(EXEC): $(OBJS)
	@-$(GCC) $(CFLAGS) msg1 msg1.o
	@-$(GCC) $(CFLAGS) msg2 msg2.o

#shm1.o: shm1.c shm_com.h
#	$(GCC) -c shm1.c $(CFLAGS) shm1.o
#shm2.o: shm2.c shm_com.h
#	$(GCC) -c shm2.c $(CFLAGS) shm2.o
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
