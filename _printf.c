#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>

/**
 * _printf - Receives the main string and all the necessary parameters to
 * print a formated string
 * @format: A string containing all the desired character
 * Return: A total count of the characters printed
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int len = 0;
	int i = 0;
	char *s;

	va_start(ap, format);
	if (format)
	{
		while (*(format + i))
		{
			switch (*(format + i))
			{
				case '%':
					write(1, "", 0);
					i++;
					switch (*(format + i))
					{
						case '%':
							write(1, "%", 1);
							i++;
							len += 1;
							continue;
						case 'c':
							s = va_arg(ap, int);
							write(1, &s, 1);
							i++;
							len += 1;
							continue;
						case 's':
							s = va_arg(ap, char *);
							write(1, s, strlen(s));
							i++;
							len += strlen(s);
							continue;
					}
			}
			write(1, format + i, 1);
			i++;
			len += 1;
		}
	}
	va_end(ap);
	return (len);
}
