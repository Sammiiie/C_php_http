php:
	ld -r -b binary script.php data.o
exe:
	gcc main.c data.o -o runme