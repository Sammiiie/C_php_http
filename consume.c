#include <stdio.h>
#include <stdlib.h>

int consume(char *url, char *body);

int consume(char *url, char *body) {
     char cmdbuf[80];
     
     url = "check-pos-get-banks"; 
     body = "{sn : 210210933}";
     snprintf (cmdbuf, sizeof(cmdbuf), "runme.exe %s %s", url, body);
     int retcod = system(cmdbuf);
     
}

