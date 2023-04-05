/*
	Processa lista linear de numeros por ENCADEAMENTO.
	Versao do arquivo 63_ED-Listas-lineares.pdf 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0
//Munas: vamos rodar pipipi 

struct regLista	{ 	int valor;
					struct regLista *prox;
				};	
typedef struct regLista TItem;

typedef struct { TItem *inicio, *final;
				 int qtde, soma; } TLista;

void inicializalista ( TLista *);
int IncluiItem(TLista *, int);
void ImprimeLista(TLista ,char *);


int main(void)
{	int numero;
	TLista lista;
	TItem *aux, *ant;

	inicializalista(&lista);
	
	while (1)
	{	printf("Informe o numero:\n");
		scanf("%d", &numero);

		if (numero < 0)
			break;
		if(IncluiItem(&lista, numero) == FALSE)
		{
			puts("memoria insuficiente para esta operacao...");
			return 2;
		}
			

		
	}
	
	/* imprimindo os valores da lista */
	
	ImprimeLista(lista, "Conteudo da Lista:");
	

		while(1)
		{	
			printf("Informe um valor\n");
			scanf("%d", &numero);
			
			if (numero < 0)
			break;
			
			aux = lista.inicio;
			ant = NULL;
			
			while ( aux != NULL && aux->valor != numero)
			{
				ant = aux;
				aux = aux->prox;
			}

			if (aux == NULL)
				puts("valor nao encontrado na lista");
			else
			{
				if (ant == NULL)
					lista.inicio = aux->prox;
				else
					ant->prox = aux->prox;
				
				/* Atualizando os demais descritores da lista */
				lista.qtde--;
				lista.soma = lista.soma - aux->valor;
				lista.final = ant;
				
				if (aux == lista.final)
				lista.final = ant;
				
				free(aux); //voa fdp
				
				ImprimeLista(lista, "Conteudo da Lista:");
				
			}
		}
		
	
	return 0;
}

void inicializalista ( TLista *lista)
{
	/* inicializando o conjunto de descritores da lista */
	lista->inicio = NULL;
	lista->final = NULL;
	lista->qtde = 0;
	lista->soma = 0;
}

int IncluiItem(TLista *lista, int num)
{
	TItem *aux;
		
	/* criando uma variável struct regLista dinamicamente */
		aux = (TItem*) malloc(sizeof(TItem));
		if (aux == NULL)
			return FALSE;
		
		/* preenchendo os campos da variável criada dinamicamente */		
		aux->valor = num;
		aux->prox = NULL;
		
		/* fazendo o encadeamento do novo item na lista */
		if (lista->inicio == NULL)
			lista->inicio = aux;
		else
			lista->final->prox = aux;
		
		lista->final = aux;
		lista->qtde++;
		lista->soma += num;
		
		return TRUE;
}

void ImprimeLista (TLista lst, char *cabec)
{
	TItem *aux;

				if(lst.inicio == NULL)
					puts("Lista vazia");
				else
				{				
					printf("\n\n\nNovo conteudo da lista:\n");
					aux = lst.inicio;
				
				
					while (aux != NULL)
					{	printf("%d\n", aux->valor);
				
						aux = aux->prox;
					}
				
						
						printf("A soma: %d e media: %.2f \n", lst.soma, lst.soma / (float) lst.qtde);
				}
}


