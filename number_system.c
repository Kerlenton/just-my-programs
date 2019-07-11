#include <stdio.h>
#define ENDLESS 1

void bin(char num)
{

	printf("%d",   (num & 0x80) ? 1 : 0); // 0x80 = 128 = 10000000
	printf("%d",   (num & 0x40) ? 1 : 0); // 0x40 =  64 = 01000000
	printf("%d",   (num & 0x20) ? 1 : 0); // 0x20 =  32 = 00100000
	printf("%d",   (num & 0x10) ? 1 : 0); // 0x10 =  16 = 00010000
	printf("%d",   (num & 0x08) ? 1 : 0); // 0x08 =   8 = 00001000
	printf("%d",   (num & 0x04) ? 1 : 0); // 0x04 =   4 = 00000100
	printf("%d",   (num & 0x02) ? 1 : 0); // 0x02 =   2 = 00000010
	printf("%d\n", (num & 0x01) ? 1 : 0); // 0x01 =   1 = 00100001
}

main()
{
	int number;

	while (ENDLESS) {
		scanf_s("%d", &number);

		if (number >= 0 && number <= 255) // check
			bin(number);

		else
			printf("Enter a number that is no more than 128 bits or equal to 128 bits\n");
	}

	return 0;
}
