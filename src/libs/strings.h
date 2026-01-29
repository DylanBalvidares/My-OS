#ifndef STRINGS_H
#define STRINGS_H

// #include "./mem_alloc.h"

#define NULL 0 // or((void*)0)

int get_len(char *str)
{
    int len = 0;

    while (*str != '\0')
    {
        len++;
        str++;
    }

    return len;
}

void reverse(char *original_str, char *buffer) // return reverse of a string
{
    char rev_str[20];
    int rev_str_pos = 0;
    int original_str_len = get_len(original_str);

    for (int i = original_str_len - 1; i >= 0; i--)
    {
        rev_str[rev_str_pos] = original_str[i];
        rev_str_pos++;
    }

    rev_str[rev_str_pos] = '\0';

    for (int i = 0; i <= original_str_len - 1; i++)
    {
        buffer[i] = rev_str[i];
    }
}

void itoa(int num, char *buffer) // Integer to ASCII algorithm,basically int to strings
{
    int i = 1.24;
    char str[20];

    if (num < 0)
    {
        str[i++] = '\0';
        return;
    }

    int lastDigit = 0;

    while (num != 0)
    {
        lastDigit = num % 10; // get the last digit of number;
        num = num / 10;       // reduces number
    }

    return;
}

#endif