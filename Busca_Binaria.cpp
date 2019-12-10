/*  ___________________________________________
    
	Programa: 			Busca Binaria
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
#include <time.h>

//Constantes
#define MAX 5

//Pilha
typedef struct ficha
{
	int cod;
	char letra;
}Ficha;

int pesquisaBin(int busca, Ficha v[], int inicio, int fim)
{
	int meio=(inicio+fim)/2;
	if(v[meio].cod==busca)
	{
		return (meio);
	}
	if(inicio>=fim)
	{
		return (-1);
	}
	else
	{
		if(v[meio].cod<busca)
		{
			return (pesquisaBin(busca, v, meio+1, fim));
		}
		else
		{
			return (pesquisaBin(busca, v, inicio, meio-1));
		}
	}	
}

void merge(Ficha v[], int inicio, int meio, int fim) {
    int com1=inicio, com2=meio+1, comAux=0, tam=fim-inicio+1;
    Ficha *vetAux;
    vetAux=(Ficha*)malloc(tam*sizeof(Ficha));
    while(com1<=meio && com2<=fim)
	{
        if(v[com1].cod<v[com2].cod)
		{
            vetAux[comAux].cod=v[com1].cod;
            vetAux[comAux].letra=v[com1].letra;
            com1++;
    	}
		else
		{
            vetAux[comAux].cod=v[com2].cod;
            vetAux[comAux].letra=v[com2].letra;
            com2++;
        }
        comAux++;
    }
    while(com1<=meio)
	{  //Caso ainda haja elementos na primeira metade
        vetAux[comAux].cod=v[com1].cod;
        vetAux[comAux].letra=v[com1].letra;
        comAux++;
        com1++;
    }
    while(com2<=fim)
	{   //Caso ainda haja elementos na segunda metade
        vetAux[comAux].cod=v[com2].cod;
        vetAux[comAux].letra=v[com2].letra;
        comAux++;
        com2++;
    }
    for(comAux=inicio; comAux<=fim; comAux++) //troca comAux<=fim por comAux<=tam
	{    //Move os elementos de volta para o vetor original
        v[comAux].cod=vetAux[comAux-inicio].cod;
        v[comAux].letra=vetAux[comAux-inicio].letra;
    }
    free(vetAux);
}

void mergeSort(Ficha v[], int inicio, int fim)
{
    if (inicio<fim)
	{
		int meio=(fim+inicio)/2;
        mergeSort(v, inicio, meio);
        mergeSort(v, meio+1, fim);
        merge(v, inicio, meio, fim);
    }
}

void exibeVetor(Ficha v[])
{
	for(int i=0; i<MAX; i++)
	{
		printf(" (%2d-%c)", v[i].cod, v[i].letra);
	}
}

//Programa principal
int main(void)
{
	Ficha vetor[MAX];
	Ficha vetorOrd[MAX];
	srand(time(NULL));
	int busca;
	int temp;
	for(int i=0; i<MAX; i++)
	{
		vetor[i].cod=rand()%100;
		vetor[i].letra=rand()%26+'A';
		vetorOrd[i].letra=vetor[i].letra;
		vetorOrd[i].cod=vetor[i].cod;
	}
	printf("\n Vetor Original -> ");
	exibeVetor(vetor);
	mergeSort(vetorOrd, 0, MAX-1);
	printf("\n Vetor Orden. ---> ");
	exibeVetor(vetorOrd);
	printf("\n\n Digite o codigo que deseja recuperar: ");
	scanf(" %d", &busca);
	temp=pesquisaBin(busca, vetorOrd, 0, MAX);
	printf("\n--------------------------------");
	printf("\n Posicao..... %2d\n Numero...... %2d\n Letra....... %2c", temp+1, vetorOrd[temp].cod, vetorOrd[temp].letra);
}


