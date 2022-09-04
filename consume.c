#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
     char cmdbuf[80];
     char i, j;
     char *url = "check_pos"; 
     char *body = "{sn : 210210933}";
     snprintf (cmdbuf, sizeof(cmdbuf), "runme.exe %d %d", i+j, i*j);
     int retcod = system(cmdbuf);
}