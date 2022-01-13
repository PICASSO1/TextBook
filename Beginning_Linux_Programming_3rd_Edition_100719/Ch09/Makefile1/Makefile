
myapp: main.o 2.o 3.o
	gcc -o myapp main.o 2.o 3.o

main.o: main.c a.h
	gcc -c main.c

2.o: 2.c a.h b.h
	gcc -c 2.c

3.o: 3.c b.h c.h
	gcc -c 3.c

.PHONY: cleanall clean
clean:
	rm -vf *.o 1> /dev/null 2>&1
cleanall: clean
	rm -vf myapp 2> /dev/null 1>&2
