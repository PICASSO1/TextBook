
all: myapp

# Which compiler
CC := gcc

# Where to install
INSTDIR = /usr/local/bin/

# Where are include files kept
INCLUDE = ./

# Options for developement
CFLAGS = -g -Wall -ansi

# Options for release
CFLAGS = -O -Wall -ansi

# Local Libraries
MYLIB = mylib.a

AR := ar
ARFLAGS := -crsv

myapp: main.o $(MYLIB)
	$(CC) -o myapp main.o $(MYLIB)

main.o: main.c a.h
#	$(CC) -I$(INCLUDE) $(CFLAGS) -c main.c

$(MYLIB): 2.o 3.o
	$(AR) $(ARFLAGS) $(MYLIB) 2.o 3.o

2.o: 2.c a.h b.h
#	$(CC) -I$(INCLUDE) $(CFLAGS) -c 2.c

3.o: 3.c b.h c.h
#	$(CC) -I$(INCLUDE) $(CFLAGS) -c 3.c

#.PHONY: cleanall clean install
clean:
	rm -vf *.o 1> /dev/null 2>&1

cleanall: clean
	rm -vf myapp 2> /dev/null 1>&2
	rm -vf $(INSTDIR)myapp
