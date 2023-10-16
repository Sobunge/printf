#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...) 
{
	va_list args;
	va_start(args, format);

	int chars_printed = 0;

	for (int i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			putchar(format[i]);
			chars_printed++;
	} else
		{
			i++; // Move past '%'
			if (format[i] == 'c')
				{
					int c = va_arg(args, int);
					putchar(c);
					chars_printed++;
				} else if (format[i] == 's')
					{
						char *str = va_arg(args, char *);
						while (*str != '\0')
						{
							putchar(*str);
							str++;
							chars_printed++;
                				}
					} else if (format[i] == '%')
						{
							putchar('%');
							chars_printed++;
						} else
						{
							// Handle unknown conversion specifiers
							putchar('%');
							putchar(format[i]);
							chars_printed += 2;
						}
		}
}
