#ifndef MAIN_H
#define MAIN_H

#include "_puttypes.h"
#include <stdarg.h>

void handle_specifier(char specifier, int *len, va_list argv);
int _printf(const char *format, ...);

#endif
