#ifndef STRINGS_H
#define STRINGS_H

// #include "./mem_alloc.h";when implements malloc function,remove the buffers of the parameters functions
#include "../libs/types.h"

#define NULL 0 // or((void*)0)

BOOL strcopy(char *dest, const char *src);
int strlen(const char *str);
void reverse(const char *original_str, char *buffer);
void itoa(const int num, char *buffer);

#endif