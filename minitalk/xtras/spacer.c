#include <stdio.h>

int main(int argc, char *argv[])
{
	int  c;

	while ((c = getchar()) != EOF)
	{
		if (c != '\n')
			putchar(c);
		putchar(c);
	}
	return 0;
}
