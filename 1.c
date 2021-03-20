#include <stdio.h>
int main()
{
	int i = 1, j = 1;
	for (; i <= 9; i++)
	{
		for (j = 1; j <= i; j++)
		{
			printf("%dx%d=%-3d", i, j, i * j);
		}

		printf("\n");
	}

	return 0;
}