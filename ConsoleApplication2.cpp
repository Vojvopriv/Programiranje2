#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
#include<string.h>

char* konkatenacija(int, ...);

int main()
{
	char* s;

	s = konkatenacija(3, "Darijo", " . ", "Prerad");
	printf("%s", s);

	free(s);
	return 0;
}

char* konkatenacija(int n, ...)
{
	char* result = 0, * next;
	int i;
	va_list args;
	va_start(args, n);

	for (i = 0; i < n; i++)
	{
		int len = result ? strlen(result) : 0;
		next = va_arg(args, char*);
		char* tmp = (char*)malloc(len +
			strlen(next) + 1);

		strcpy_s(tmp,10 , result ? result : "");
		strcat_s(tmp, 30, next);

		free(result);
		result = tmp;
	}

	va_end(args);
	return result;
}