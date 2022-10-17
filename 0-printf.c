#include "main.h"

/**
 * _printf - prints character and sends input into the standard output
 * @format: the format string
 * Return: always 0
 */

int _printf(const char *format, ...)
{
    int i = 0, length = 0, j = 0;

    length = string_length(format, j);

    va_list args;
    va_start(args, format);

    while (i < length)
    {
        if (format[i] != '%')
        {
           write_char(format[i]);
        } else
        {
            i++;
            switch(format[i])
            {
                case 'd':
                {
                    int x = va_arg(args, int);
                    write_char(x + '0');
                }
            }
        }
        i++;
    }
    va_end(args);
    return (0);
}

int string_length(const char *string, int x)
{
    if (*string != '\0')
    {
        return (string_length(string + 1, x + 1));
    }
        return (x);
}

int write_char(char c)
{
    return(write(1, &c, 1));
}
