#include <stdio.h>

int main()
{
	int ch = 'a';
	int j = 0;
	int i = 0;

	while (j < 8)
	{
		if (ch & 1 << j)
			i |= (1 << j);
		// else
		// {
		// 	i = ch & 1;
		// }
		j++;
	}
	// i = ch & 1;
	printf("ch = %d, i = %d ", ch ,i);
}
