CFLAGS = -g

people: people.c
	gcc -Wall -o people people.c
person: person.c
	gcc -Wall -o person readln.c person.c
nl: readln.c nl-v1.c
	gcc -o nl-v1 readln.c nl-v1.c

clean:
	rm readln
