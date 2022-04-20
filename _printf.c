#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/**
 * _printf - printf function
 * @format: const char pointer
 * Return: b_len
 */
int _printf(const char *format, ...)
{
	va_list list;
	int i = 0; j = 0;
	char *dest;

	dest = malloc(sizeof(char) * 1500);
	if (dest == NULL)
		return (1);
	va_start(list, format);
	while(format[i] != '\0')
	{
		if (format == '%')
		{
			i++;
			if (format[i] == 'c')
			{
				dest[j] = (char)va_arg(list, int);
				j++;
			}
		}
		else
		{
			dest[j] = format[i];
			j++;
		}
		i++;
	}
	write(1, dest, i++);
	va_end(list);
	free(list);
	return (i);
}
