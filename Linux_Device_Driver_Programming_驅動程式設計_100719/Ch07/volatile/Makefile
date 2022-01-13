
GCC := gcc
CFLAGS := -S
FILE := user.c
EXEC := user
ASSEMBLY := user.s
RM := rm -rf

.PHONY: all
all: $(ASSEMBLY)

$(ASSEMBLY): 
	@-$(GCC) $(CFLAGS) $(FILE)

.PHONY: clean cleanall install print tar dist TAGS check test
clean:
	@-$(RM) *.s

cleanall: clean

install:

print:

tar:

dist:

TAGS:

check: 

test:
