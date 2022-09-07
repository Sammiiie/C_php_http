#ifndef CONCATF_H
#define CONCATF_H

#if defined(__GNUC__) && ! defined(_GNU_SOURCE)
#define _GNU_SOURCE /* needed for (v)asprintf, affects '#include <stdio.h>' */
#endif
#include <stdio.h>  /* needed for vsnprintf    */
#include <stdlib.h> /* needed for malloc, free */
#include <stdarg.h> /* needed for va_*         */

// #ifdef _MSC_VER
int vasprintf(char **strp, const char *format, va_list ap);
int concatf(char **strp, const char *format, ...);
// #endif

#endif // CONCATF_H