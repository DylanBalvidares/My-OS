#include <stdio.h>
#include <string.h>

void reverse(char *original_str, char *buffer)
{
    int original_str_len = strlen(original_str);
    char rev_str[4];

    int rev_str_pos = 0;

    for (int i = original_str_len - 1; i >= 0; i--)
    {
        rev_str[rev_str_pos] = original_str[i];
        rev_str_pos++;
    }

    rev_str[rev_str_pos] = '\0';
    strcpy(buffer,rev_str);
}

int main()
{
    
    int num = 841;
    int last_digit;
    char ascii_digit;
    char str[4];
    char final_str_buffer[4];

    int i = 0;

    int aux = num;
    while (aux != 0)
    {
        last_digit = aux % 10;          
        ascii_digit = '0' + last_digit; 
        aux = aux / 10;                 
        str[i] = ascii_digit;
        i++;
    }

    str[i] = '\0';
    
    reverse(str, final_str_buffer);
    
    printf("[%d] number is [%s] in string\n",num, final_str_buffer);

    return 0;
}