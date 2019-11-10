#include <stdio.h>

int		main()
{
	int		i;

	i = -10;
	printf("%i\n", i);
	printf("%1$d\n", i);
	printf("%010d\n", i);
	printf("%-10d\n", i);
	printf("%10d\n", i);
	printf("%*d\n", 10, i);
	printf("%1$*1$d\n", i);
	printf("%.6i\n", i);
	return (0);
}
