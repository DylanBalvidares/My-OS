#ifndef STRINGS_H
#define STRINGS_H

// #include "./mem_alloc.h";when implements malloc function,remove the buffers of the parameters functions
#include "./types.h"

#define NULL 0 // or((void*)0)

BOOL str_copy(char *dest, const char *src);
int get_len(const char *str);
void reverse(const char *original_str, char *buffer);
void itoa(const int num, char *buffer);

BOOL str_copy(char *dest, const char *src)
{
    //...check if dest capacity is ok//NOT IMPLEMENTED YET

    int i = 0;

    do
    {
        dest[i] = src[i];
        i++;
    } while (src[i] != '\0');

    return get_len(src) == get_len(dest);
}

int get_len(const char *str)
{
    int len = 0;

    while (*str != '\0')
    {
        len++;
        str++;
    }

    return len;
}

void reverse(const char *original_str, char *buffer) // return reverse of a string
{
    int original_str_len = get_len(original_str);
    char final_str[4];

    int rev_str_pos = 0;

    for (int i = original_str_len - 1; i >= 0; i--)
    {
        final_str[rev_str_pos] = original_str[i];
        rev_str_pos++;
    }

    final_str[rev_str_pos] = '\0';
    str_copy(buffer, final_str);
}

void itoa(const int num, char *buffer) // Integer to ASCII algorithm,basically int to strings
{
    int i = num;
    int last_digit;
    char ascii_val;
    char str[4];
    char final_buffer[4];
    int j = 0;
    int aux = num;

    /*NOT IMPLEMENTED YET
    if(num < 0){}*/

    while (aux != 0)
    {
        last_digit = aux % 10;
        ascii_val = '0' + last_digit;
        aux = aux / 10;
        str[j] = ascii_val;
        j++;
    }

    str[j] = '\0';

    reverse(str, final_buffer);

    str_copy(buffer, final_buffer);
    return;
}

#endif