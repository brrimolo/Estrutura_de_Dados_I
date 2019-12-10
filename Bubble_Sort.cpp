/*  ___________________________________________
    
	Programa: 			Bubble Sort
	Autor:    			Bruno Ramalho Rimolo
	Materia:            Estrutura de Dados 1
	Docente:            Angelo Cnop
	Data criacao:  		11/10/2019
	Ult. Atualizacao:   11/10/2019
	___________________________________________
*/

//Declaracao de Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

//Constantes
#define x 5

//Funcoes
void BubbleSort(int *ptr)
{
	int i, j, aux;
	//Varre os ponteiros para fazer as ordenacoes
	for(i=0; i<x; i++)
	{
		for(j=0; j<x-1; j++)
		{
			if(ptr[j]>ptr[j+1])
			{
				aux=ptr[j];
				ptr[j]=ptr[j+1];
				ptr[j+1]=aux;
			}
		}
	}
}

//Programa principal
int main(void)
{
	int i;
	int vetor[x];
	//Ponteiro apontando para o endereco 0 do vetor
	int *ptr_vetor=&vetor[0];
	printf("\nEntre com os valores do vetor de %d posicoes: \n\n", x);
	for(i=0; i<x; i++)
	{
		printf(" Vetor[%d]: ", i);
		scanf(" %d", ptr_vetor+i);
	}
	printf("\n\n VETOR ATUAL .....-> ");
	for(i=0; i<x; i++)
	{
		printf(" %d ", vetor[i]);
	}
	BubbleSort(ptr_vetor);
	printf("\n\n VETOR ORDENADO ..-> ");
	for(i=0; i<x; i++)
	{
		printf(" %d ", vetor[i]);
	}
}
