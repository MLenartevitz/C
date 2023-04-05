/*
	Processa lista linear de numeros por ENCADEAMENTO.
	Versao do arquivo 63_ED-Listas-lineares.pdf 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

struct regLista	{ 	int valor;
					struct regLista *prox;
				};	
typedef struct regLista TItem;
	
int main(void)
{	int numero,cont,soma;
	double media;
	cont = 0;
	 TItem *inicio, *aux, *ant;

	/* inicializando a variável inicio com um endereco vazio */
	inicio = NULL;
	while (1)
	{	printf("Informe o numero:\n");
		scanf("%d", &numero);

		if (numero < 0)
			break;

		/* criando uma variável struct regLista dinamicamente */
		aux = (TItem*) malloc(sizeof(TItem));
		if (aux == NULL)
		{
			printf("Memoria cheia para esta operacao patrao");
			return 2;
		}
		
		/* preenchendo os campos da variável criada dinamicamente */		
		aux->valor = numero;
		aux->prox = NULL;
		
		/* fazendo o encadeamento do novo item na lista */
		if (inicio == NULL)
			inicio = aux;
		else
			ant->prox = aux;

		ant = aux;
	}
	
	/* imprimindo os valores da lista */
	if(inicio == NULL)
		puts("Lista vazia");
	else
	{
		printf("\n\n\nConteudo da lista:\n");
	
		aux = inicio;
		
		while (aux != NULL)
		{	printf("%d\n", aux->valor);
			soma += aux->valor;
			aux = aux->prox;
			cont++;
		}
	
			media = soma / ((float)cont);
			printf("A soma dos valores eh: %d\n", soma);
			printf("A media dos valores eh: %.2lf\n", media);

		while(1)
		{	
			printf("Informe um valor\n");
			scanf("%d", &numero);
			
			if (numero < 0)
			break;
			
			aux = inicio;

			while ( aux != NULL && aux->valor != numero)
			{
				aux = aux->prox;
			}

			if (aux == NULL)
				puts("valor nao encontrado na lista");
			else
				printf("O valor %d existe na lista\n", numero);
		}
		
	}
	return 0;
}
