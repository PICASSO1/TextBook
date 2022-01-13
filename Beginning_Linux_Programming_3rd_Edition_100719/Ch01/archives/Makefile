
GCC := gcc
CFLAGS := -c -g -DDEBUG
OBJS := fred.o bill.o program.o
EXEC := program
RM := rm -rf
LIBS := libfoo.a
AR := ar -crsv

.PHONY: all
all: $(EXEC)

$(EXEC): program.o libfoo.a
#	@-$(GCC) -o $(EXEC) program.o $(LIBS)
	@-$(GCC) -o $(EXEC) program.o -L./ -lfoo

$(LIBS): fred.o bill.o
	@-$(AR) $(LIBS) fred.o bill.o

$(OBJS): %.o: %.c
	@-$(GCC) $(CFLAGS) $< -o $@

.PHONY: clean cleanall install print tar dist TAGS check test
clean:
	@-$(RM) *.o *.a

cleanall: clean
	@-$(RM) $(EXEC)

install:

print:

tar:

dist:

TAGS:

check: 

test:
