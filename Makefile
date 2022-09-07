php:
	ld -r -b binary script.php data.o
exe:
	gcc build.c concatf.c data.o -o runas