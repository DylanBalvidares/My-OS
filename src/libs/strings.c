#include "../libs/strings.h"

BOOL strcopy(char *dest, const char *src)
{
    //...check if dest capacity is ok//NOT IMPLEMENTED YET

    int i = 0;

    do
    {
        dest[i] = src[i];
        i++;
    } while (src[i] != '\0');

    return strlen(src) == strlen(dest);
}

int strlen(const char *str)
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
    int original_str_len = strlen(original_str);
    char final_str[4];

    int rev_str_pos = 0;

    for (int i = original_str_len - 1; i >= 0; i--)
    {
        final_str[rev_str_pos] = original_str[i];
        rev_str_pos++;
    }

    final_str[rev_str_pos] = '\0';
    strcopy(buffer, final_str);
}

void itoa(const int num, char *buffer) // Integer to ASCII algorithm,basically int to strings
{
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

    strcopy(buffer, final_buffer);
}
