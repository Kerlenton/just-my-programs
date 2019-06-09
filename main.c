#include <stdio.h>
#define TRUE 1

main()
{
	float x, y;
	char symbol;

	while (TRUE) {
		printf("Calculator -> ");
		scanf("%f %c %f", &x, &symbol, &y);

		switch (symbol) {
		case '+': printf("Result -> %.2f\n", x + y); break;
		case '-': printf("Result -> %.2f\n", x - y); break;
		case '*': printf("Result -> %.2f\n", x*y); break;
		case '/': printf("Result -> %.2f\n", x / y); break;
		default: printf("Operator don't found:(\n");
		}
	}
	return 0;
}
