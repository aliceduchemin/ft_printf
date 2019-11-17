#include <stdio.h>

int		main()
{
	int		i;

	i = 0;
/*	printf("larg = 4 prec = 15 : %0*.*d\n", 4, 15, 20);
	printf("larg = 15 prec = 4 : %0*.*d\n", 15, 4, 20);
	printf("larg = 15 : %0*d\n", 15, 20);
	printf("prec = 15 : %0.*d\n\n\n", 15, 20);
	printf("larg = 4 prec = 15 : %-*.*d\n", 4, 15, 20);
	printf("larg = 15 prec = 4 : %-*.*d\n", 15, 4, 20);
	printf("larg = 15 : %-*d\n", 15, 20);
	printf("prec = 15 : %-.*d\n\n\n", 15, 20);
	printf("larg = 4 prec = 15 : %*.*d\n", 4, 15, 20);
	printf("larg = 15 prec = 4 : %*.*d\n", 15, 4, 20);
	printf("larg = 15 : %*d\n", 15, 20);
	printf("prec = 15 : %.*d\n", 15, 20);
	
*/	printf("%1$*1$d\n", i);
	printf("%1$d\n", i);
	printf("%1$05.6d\n", i);
	printf("%1$0*2$.6d\n", i, 5);
	printf("%1$0*2$.*3$d\n", i, 5, 6);
	printf("test %3$0*2$.*1$d\n", i, 5, 6);
	printf("%0*.*d\n", 5, 6, i);
	printf("%0*.6d\n", 5, i);
	printf("%05.6d\n\n", i);

	printf("%010d\n", i);
//	printf("%%\n");
	printf("%10d\n\n", i);
	
	printf("%*d\n", 10, i);
	printf("%.6d\n", i);
	printf("%.*d\n", 6,  i);
	
	printf("%.0d\n", i);
//	printf("%1$s, %2$0*3$.6d\n", "lol", i, 5);
	return (0);
}
