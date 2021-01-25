#include <stdio.h>
#include <string.h>

int main()
{
	char *str = strdup("Hello World!\n");

	while (1)
		printf("%s", str);

}
