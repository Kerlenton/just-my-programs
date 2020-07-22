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
	ch->next = NULL;

	return ch;
}

RNA *init_rna()
{
	RNA *rna = (RNA*)malloc(sizeof(RNA));
	rna->chain = (chain_t*)malloc(sizeof(chain_t));
	rna->chain->next = NULL;

	return rna;
}

DNA *init_dna()
{
	DNA *dna = (RNA*)malloc(sizeof(RNA));

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
	if (chain->next == NULL)
	{
		chain->first = nuc;
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

int main(void)
{
	setlocale(LC_ALL, "Rus");

	/*nucleotide n, n2;
	n.nitrogenous_base = 'А';
	n2.nitrogenous_base = 'Ц';

	chain_t *chain = (chain_t*)malloc(sizeof(chain_t));
	chain->first = &n;
	chain->next = (chain_t*)malloc(sizeof(chain_t));
	chain->next->first = &n2;
	chain->next->next = NULL;

	DNA *dna = (DNA*)malloc(sizeof(DNA));
	dna->chain1 = (nucleotide*)malloc(sizeof(nucleotide));

	dna->chain1 = chain;

	RNA *rna = (RNA*)malloc(sizeof(RNA));

	transcription(dna, rna);

	printf("%c", rna->chain->first->nitrogenous_base);*/

	nucleotide n = 'Г';
	//nucleotide k = ' ';
	chain_t *ch = create_chain(n);
	//chain_t *kh = create_chain(k);
	chain_push_back(ch, 'Г');

	//RNA *rna = create_rna(kh, 'v');
	RNA *rna = init_rna();
	DNA *dna = create_dna(ch, ch);

	transcription(dna, rna);

	printf("%c", dna->chain1->first);
	printf("%c", rna->chain->next->first);

	system("PAUSE");
	return 0;
}
