/*  ___________________________________________
    
	Programa: 			Pilha
	Autor:    			Bruno Ramalho Rimolo
	Materia:            Estrutura de Dados 1
	Docente:            Angelo Cnop
	Data criacao:  		01/12/2019
	Ult. Atualizacao:   01/12/2019
	___________________________________________
*/

//Declaracao de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

//Constantes
#define MAX 5

//Variaveis globais
int inicio, fim;

//Pilha
typedef struct pilha
{
	int topo;
	int capacidade;
	int valor;
	int *ptr_elemento;
}Pilha;



void criarPilha(Pilha *p, int c)
{
	p->topo = -1;           	 		               //indicador de pilha vazia
	p->capacidade = c;   	   		                   //capacidade vai valer c
	p->ptr_elemento = (int*) malloc(c*sizeof(int));    //ponteiro prox elemento
	
}
//Pilha vazia
int pilhaVazia()
{
	return (inicio==fim);
}
//Pilha cheia
int pilhaCheia()
{
	return (fim==MAX);
}

// Insere item na Pilha
int push(Pilha *p, int a)
{
	if(!pilhaCheia())
	{
		p->topo++;
		p->ptr_elemento [p->topo]=a;
		fim++;
	}
	else
	{
		printf("\nPilha esta cheia ! [overflow]\n");
	}
}
// Remove item da pilha
int pop(Pilha *p)
{
	int aux;
	aux = p->ptr_elemento [p->topo];
	if(!pilhaVazia())
	{
		p->topo--;
		fim--;
		printf("\n%d removido com sucesso\n\n", aux);
		return(aux);
	}
	else
	{
		printf("\nEsta pilha esta vazia ! [underflow]\n");
	}
}

void mostrarPilha(Pilha *p)
{
	for(int i=inicio; i<fim; i++)
	{
		printf(" %d ", p->ptr_elemento[i]);
	}
}

//Programa principal
int main(void)
{
	Pilha minhapilha;
	inicio=0;
	fim=0;
	int opcao=0;
	int valor=0;
	criarPilha(&minhapilha, MAX);

	// apresenta menu
	while(1)
	{
		printf("\n1 - Inserir elemento\n2 - Remover elemento\n3 - Mostrar Pilha \n0 - Sair\n\nOpcao? ");
		scanf("%d", &opcao);
		switch(opcao)
		{
			case 0: exit(0);

			case 1: // insere elemento
				printf("\nValor do elemento a ser inserido? ");
				scanf(" %d", &valor);
				push(&minhapilha, valor);
				break;
			case 2: // remove elemento
				valor = pop(&minhapilha);
				; 
				break;

			case 3: // mostrar pilha
				printf("\nConteudo da pilha => " );
				mostrarPilha(&minhapilha);							
				break;
			default:
				printf("\nOpcao Invalida\n\n");
		}
	}
}


