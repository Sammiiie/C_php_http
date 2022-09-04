#include <stdio.h>  /* needed for vsnprintf    */
#include <stdlib.h> /* needed for malloc, free */
#include <stdarg.h> /* needed for va_*         */

char* concatf(const char *fmt, ...) {
  char* buf = NULL;
  va_list args;
  va_start(args, fmt);
  int n = _vscprintf(fmt, args);
  va_end(args);
  if (n >= 0) {
    va_start(args, fmt);
    buf = malloc(n+1);
    if (buf) _vsnprintf(buf, n+1, fmt, args);
    va_end(args);
  } 
  return buf;
}

// int asprintf(char **strp, const char *format, ...)
// {
//     va_list ap;
//     va_start(ap, format);
//     int retval = vasprintf(strp, format, ap);
//     va_end(ap);
//     return retval;
// }