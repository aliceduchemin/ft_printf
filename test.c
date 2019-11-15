#include <stdio.h>

int		main()
{
	int		i;

	i = -10;
	printf("%0*d\n", 5,  i);
	printf("%-10d\n\n", i);
	
	printf("%1$*1$d\n", i);
	printf("%1$d\n", i);
	printf("%1$05.6d\n", i);
	printf("%1$0*2$.6d\n", i, 5);
	printf("%1$0*2$.*3$d\n", i, 5, 6);
	printf("test %3$0*2$.*1$d\n", i, 5, 6);
	printf("%0*.*d\n", 5, 6, i);
	printf("%0*.6d\n", 5, i);
	printf("%05.6d\n\n", i);
	
	printf("%010d\n", i);
	printf("%%\n");
	printf("%10d\n\n", i);
	
	printf("%*d\n", 10, i);
	printf("%.6i\n", i);
	printf("%.*i\n\n", 6,  i);
//	printf("%.*1$i\n", 6,  i);
	
	printf("%d\n", i);
	return (0);
}
