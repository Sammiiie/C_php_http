#include "asprintf.h"

#include <stdio.h>
#include <stdlib.h>

extern char _binary_script_php_start;
extern char _binary_script_php_end;

int main(int argc, char *argv[]) {
    // EXTRACT OUR RESOURCE OBJECT INTO /tmp/test.php
    char *p = &_binary_script_php_start;
    FILE *fp = fopen("/tmp/test.php","wb");
    while ( p != &_binary_script_php_end ) {
        fputc(*p++,fp);
    }
    fclose(fp);
    // NOW READ IN OUR STANDARD ARGUMENTS AND LAUNCH OUR COMMAND
    int i = 1;
    char *cmd = "php /tmp/test.php";
    char *s = NULL;
    asprintf(&s, "%s",cmd);
    for(i = 1; i < argc; i++) {
        asprintf(&s, "%s \"%s\"",s,argv[i]);
    }
    // concatf("%s",cmd);
    // for(i = 1; i < argc; i++) {
    //     concatf("%s \"%s\"",s,argv[i]);
    // }
    // concatf(&s, "%s",cmd);
    // for(i = 1; i < argc; i++) {
    //     concatf(&s, "%s \"%s\"",s,argv[i]);
    // }
    system(s);
    free(s);
    unlink("/tmp/test.php"); // comment me out for debugging if you want
}