#include <stdio.h>
#define TRUE 1

main()
{
	double x, y;
	char symbol;

	while (TRUE) {
		printf("Calculator -> ");
		scanf("%lf %c %lf", &x, &symbol, &y);

		switch (symbol) {
		case '+': printf("Result -> %.2lf\n", x + y); break;
		case '-': printf("Result -> %.2lf\n", x - y); break;
		case '*': printf("Result -> %.2lf\n", x*y); break;
		case '/': printf("Result -> %.2lf\n", x / y); break;
		default: printf("Operator don't found:(\n"); break;
		}
	}
	return 0;
}
