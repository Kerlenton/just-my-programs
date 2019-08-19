#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <stdbool.h>

main()
{
	bool value = true;
	srand(time(NULL));

	printf("--------------------------\n");

	while (value)
	{
		uint16_t choice_1, choice_2 = 1 + rand() % 3;

		printf("1 - Rock\n2 - Scissors\n3 - Paper\n\n");
		printf("Your choice -> ");
		scanf_s("%hd", &choice_1);
		printf("--------------------------\n");
		printf("Machine chose %s\n", (choice_2 == 1) ? "rock" : (choice_2 == 2) ? "scissors" : "paper");

		if (choice_1 == choice_2)
			printf("==Draw==\n");

		else if (choice_1 == 1)
		{
			if (choice_2 == 2)
				printf("==You win==\n");

			else
				printf("==Machine win==\n");
		}

		else if (choice_1 == 2)
		{
			if (choice_2 == 1)
				printf("==Machine win==\n");
			else
				printf("==You win==\n");
		}

		else if (choice_1 == 3)
		{
			if (choice_2 == 1)
				printf("==You win==\n");
			else
				printf("==Machine win==\n");
		}

		else {
			printf("Number is now defined\n");
			value = false;
		}
		printf("--------------------------\n");
	}
	return 0;
}
