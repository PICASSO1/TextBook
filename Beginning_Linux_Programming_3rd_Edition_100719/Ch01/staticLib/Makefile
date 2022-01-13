
GCC := gcc
CFLAGS := -c -g -DDEBUG
OBJS := main.o hello.o world.o
EXEC := main
RM := rm -rf
LIBS := libmain.a
AR := ar -crv

.PHONY: all
all: $(EXEC)

$(EXEC): main.o libmain.a
	@-$(GCC) -o $(EXEC) main.o -L./ -lmain

$(LIBS): hello.o world.o
	@-$(AR) $(LIBS) hello.o world.o

$(OBJS): %.o: %.c
	@-$(GCC) $(CFLAGS) $< -o $@

.PHONY: clean cleanall install print tar dist TAGS check test
clean:
	@-$(RM) *.o

cleanall: clean
	@-$(RM) $(LIBS) $(EXEC)

install:

print:

tar:

dist:

TAGS:

check: 

test:
