/*  ___________________________________________
    
	Programa: 			Bubble, Merge e Selection Sort
	Autor:    			Bruno Ramalho Rimolo
	Materia:            Estrutura de Dados 1
	Docente:            Angelo Cnop
	Data criacao:  		30/11/2019
	Ult. Atualizacao:   01/12/2019
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
#define tam 5

//contador global para funcoes recursivas
int gcont=0;

//Funcoes
void bubbleSort(int num[])
{
	int i, j, aux, cont=0;
	//Varre os ponteiros para fazer as ordenacoes
	for(i=0; i<tam; i++)
	{
		for(j=0; j<tam-1; j++)
		{
			cont++;
			if(num[j]>num[j+1])
			{
				aux=num[j];
				num[j]=num[j+1];
				num[j+1]=aux;
			}
			//Mostra cada passo da ordenacao
			printf("\n Passo %2d: Vetor --> ", cont);
			for(int k=0; k<tam; k++)
			{
				printf(" %d ", num[k]);
			}
		}
	}
}

void selectionSort(int num[]) { 
	int i, j, min, aux, cont=0;
	for (i = 0; i<(tam-1); i++) 
	{
		min=i;
		for(j=(i+1); j<tam; j++)
		{
			cont++;
			if(num[j]<num[min])
			{
				min=j;
			}
			//Mostra cada passo da ordenacao
			printf("\n Passo %2d: Vetor --> ", cont);
			for(int k=0; k<tam; k++)
			{
				printf(" %d ", num[k]);
			}
		}
		if (num[i]!=num[min])
		{
		    aux=num[i];
		    num[i]=num[min];
		    num[min]=aux;
		}
	}
}

void merge(int num[], int inicio, int meio, int fim) {
    int com1=inicio, com2=meio+1, comAux=0, tam2=fim-inicio+1;
    int *vetAux;
    vetAux=(int*)malloc(tam2*sizeof(int));
    while(com1<=meio && com2<=fim){
    	gcont++;
        if(num[com1]<num[com2])
		{
            vetAux[comAux]=num[com1];
            com1++;
    	}
		else
		{
            vetAux[comAux]=num[com2];
            com2++;
        }
        comAux++;
       	//Mostra cada passo da ordenacao
		printf("\n Passo %2d: Vetor --> ", gcont);
		for(int k=0; k<tam; k++)
		{
			printf(" %d ", num[k]);
		}
    }
    while(com1<=meio)
	{  //Caso ainda haja elementos na primeira metade
		gcont++;
        vetAux[comAux]=num[com1];
        comAux++;
        com1++;
       	//Mostra cada passo da ordenacao
		printf("\n Passo %2d: Vetor --> ", gcont);
		for(int k=0; k<tam; k++)
		{
			printf(" %d ", num[k]);
		}
    }
    while(com2<=fim)
	{   //Caso ainda haja elementos na segunda metade
		gcont++;
        vetAux[comAux]=num[com2];
        comAux++;
        com2++;
       	//Mostra cada passo da ordenacao
		printf("\n Passo %2d: Vetor --> ", gcont);
		for(int k=0; k<tam; k++)
		{
			printf(" %d ", num[k]);
		}
    }
    for(comAux=inicio; comAux<=fim; comAux++) //troca comAux<=fim por comAux<=tam2
	{    //Move os elementos de volta para o vetor original
        num[comAux]=vetAux[comAux-inicio];
    }
    free(vetAux);
}

void mergeSort(int num[], int inicio, int fim){
    if (inicio<fim)
	{
		int meio=(fim+inicio)/2;
        mergeSort(num, inicio, meio);
        mergeSort(num, meio+1, fim);
        merge(num, inicio, meio, fim);
    }
}


//Programa principal
int main(void)
{
	int i;
	int vetor[tam];
	int item;
	//Ponteiro apontando para o endereco 0 do vetor
	int *ptr_vetor=&vetor[0];
	printf("\nEntre com os valores do vetor de %d posicoes: \n\n", tam);
	for(i=0; i<tam; i++)
	{
		printf(" Vetor[%d]: ", i);
		scanf(" %d", ptr_vetor+i);
	}
	printf("\n\n VETOR ATUAL .....-> ");
	for(i=0; i<tam; i++)
	{
		printf(" %d ", vetor[i]);
	}
	printf("\n\n Escolha o metodo de ordenacao: ");
	printf("\n   1- Bubble Sort;\n   2- Selection Sort;\n   3- Merge Sort;\n   [1, 2 ou 3]: ");
	scanf(" %d", &item);
	switch(item)
	{
		case 1:
			printf("\n\n *********** BubbleSort ***********\n");
			bubbleSort(vetor);
			break;
		case 2:
			printf("\n\n ********** SelectionSort *********\n");
			selectionSort(vetor);
			break;
		case 3:
			printf("\n\n ************ MergeSort ***********\n");
			mergeSort(vetor, 0, tam-1);
			break;
		default:
			printf ("\n Valor invalido!\n");
	}
	printf("\n\n VETOR ORDENADO ..-> ");
	for(i=0; i<tam; i++)
	{
		printf(" %d ", vetor[i]);
	}
	getch();
}
