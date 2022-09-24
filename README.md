# RUN PHP CODE IN C PROGRAM
 
A simple C program to you run PHP program in terminal with arguements.

Run `ld -r -b binary script.php data.o` in your terminal to create a runnable file 
Run `gcc build.c asprintf.c data.o -o runme` in your terminal, this would combine the earlier created runnable file with the buils.c and in doing so create an executable named runme. Running runme should echo out the results of your php code.

# RUN WITH ARGUEMENTS
Build consume.c, on line 11 we create the command we want to run, passing the parameters alongside.
