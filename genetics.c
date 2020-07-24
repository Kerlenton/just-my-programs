#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <locale.h>

#define nucleotide char

typedef struct chain
{
	nucleotide first;
	struct chain *next;
} chain_t;

typedef struct
{
	chain_t *chain1;
	chain_t *chain2;
} DNA;

typedef struct
{
	chain_t *chain;
	char type;
} RNA;

chain_t *init_chain()
{
	chain_t* ch = (chain_t*)malloc(sizeof(chain_t));
	ch->first = NULL;
	ch->next = NULL;

	return ch;
}

RNA *init_rna()
{
	RNA *rna = (RNA*)malloc(sizeof(RNA));
	rna->chain = (chain_t*)malloc(sizeof(chain_t));
	rna->chain->first = NULL;
	rna->chain->next = NULL;

	return rna;
}

DNA *init_dna()
{
	DNA *dna = (RNA*)malloc(sizeof(RNA));

	dna->chain1 = (chain_t*)malloc(sizeof(chain_t));
	dna->chain2 = (chain_t*)malloc(sizeof(chain_t));

	dna->chain1->first = NULL;
	dna->chain1->next = NULL;

	dna->chain2->first = NULL;
	dna->chain2->next = NULL;

	return dna;
}

chain_t *create_chain(nucleotide nuc)
{
	chain_t* ch = (chain_t*)malloc(sizeof(chain_t));
	ch->first = nuc;
	ch->next = NULL;

	return ch;
}

RNA *create_rna(chain_t *ch, char type)
{
	RNA *rna = (RNA*)malloc(sizeof(RNA));
	rna->chain = ch;
	rna->type = type; 

	return rna;
}

DNA *create_dna(chain_t *ch1, chain_t *ch2)
{
	DNA *dna = (RNA*)malloc(sizeof(RNA));
	dna->chain1 = ch1;
	dna->chain2 = ch2;

	return dna;
}

void chain_push_back(chain_t *chain, nucleotide nuc)
{
	if (chain->next == NULL && chain->first == NULL)
	{
		chain->first = nuc;
		return;
	}

	while (chain->next != NULL)
		chain = chain->next;

	chain->next = (chain_t*)malloc(sizeof(chain_t));
	chain->next->first = nuc;
	chain->next->next = NULL;
}

void transcription(DNA *dna, RNA *rna)
{
	chain_t *p = dna->chain1;

	while (p != NULL)
	{
		if (p->first == 'Г')
			chain_push_back(rna->chain, 'Ц');
		if (p->first == 'Ц')
			chain_push_back(rna->chain, 'Г');
		if (p->first == 'А')
			chain_push_back(rna->chain, 'У');
		if (p->first == 'Т')
			chain_push_back(rna->chain, 'А');

		p = p->next;
	}
}

void translation(RNA *rna)
{

}

void printDNA(DNA *dna)
{
	chain_t *temp1 = dna->chain1;
	chain_t *temp2 = dna->chain2;
	while (temp1 != NULL)
	{
		printf("%c", temp1->first);
		temp1 = temp1->next;
	}
	putchar('\n');

	while (temp2 != NULL)
	{
		printf("%c", temp2->first);
		temp2 = temp2->next;
	}
	putchar('\n');
}

printRNA(RNA *rna)
{
	chain_t *temp = rna->chain;
	while (temp != NULL)
	{
		printf("%c", temp->first);
		temp = temp->next;
	}
	putchar('\n');
}

int main(void)
{
	setlocale(LC_ALL, "Rus");

	nucleotide n = 'Г';
	chain_t *ch = create_chain(n);

	chain_push_back(ch, 'Г');
	RNA *rna = init_rna();
	DNA *dna = create_dna(ch, ch);

	transcription(dna, rna);

	printDNA(dna);
	printRNA(rna);

	return 0;
}
