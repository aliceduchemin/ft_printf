#include <stdio.h>

int		main()
{
	int		i;

	i = 15;
/*	printf("larg = 4 prec = 15 : %0*.*i\n", 4, 15, i);
	printf("larg = 15 prec = 4 : %0*.*i\n", 15, 4, i);
	printf("larg = 15 : %0*i\n", 15, i);
	printf("prec = 15 : %0.*i\n\n", 15, i);
	printf("larg = 4 prec = 15 : %-*.*i\n", 4, 15, i);
	printf("larg = 15 prec = 4 : %-*.*i\n", 15, 4, i);
	printf("larg = 15 : %-*i\n", 15, i);
	printf("prec = 15 : %-.*i\n\n", 15, i);
	printf("larg = 4 prec = 15 : %*.*i\n", 4, 15, i);
	printf("larg = 15 prec = 4 : %*.*i\n", 15, 4, i);
	printf("larg = 15 : %*i\n", 15, i);
	printf("prec = 15 : %.*i\n", 15, i);

	printf("%1$-10d\n", i);
	printf("%1$*1$d\n", i);
	printf("%1$d\n", i);
	printf("%1$05.6d\n", i);
	printf("%1$0*2$.6d\n", i, 5);
	printf("%1$0*2$.*3$d\n", i, 5, 6);
	printf("test %3$0*2$.*1$d\n", i, 5, 6);
	printf("test %2$0*1$.0d\n", 5, 6);
	printf("%0*.*d\n", 5, 6, i);
	printf("%0*.6d\n", 5, i);
	printf("%05.6d\n\n", i);
	printf("%010d\n", i);
	printf("%10d\n", i);
	
	printf("%*d\n", 10, i);
	printf("%.6d\n", i);
	printf("%.*d\n", 6,  i);
*/	
//	printf("%c\n", 'c');
	printf("%*c\n", 5, 'a');
	//printf("%-*d\n", 5, 1);
//	printf("%1$s, %2$0*3$.6d\n", "lol", i, 5);
	return (0);
}
