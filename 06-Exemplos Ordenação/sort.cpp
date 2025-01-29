#include "sort.h"

void bubblesort(int* v, int n){
	int i, j, temp, troca = 1;

	for(i = n-1; troca && i > 0; i--){
		troca = 0;
		for (j=0; j<i; j++){
			if (v[j]>v[j+1]){ /* troca */
				temp = v[j];
				v[j] = v[j+1];
				v[j+1] = temp;
				troca = 1;
			}
		}
	}
}

void selectionsort(int *v, int n)
{
	int k, i, pmenor, tmp;
	for (k=0; k<n-1; k++)
	{
		pmenor = k;
		for(i=k+1; i<n; i++)
		{
			if(v[i] < v[pmenor])
				pmenor = i;
		}
		if(pmenor != k)
		{
			tmp = v[pmenor];
			v[pmenor] = v[k];
			v[k] = tmp;
		}
	}
}

void insertionsort(int *v, int n)
{
	int i,j,toInsert;
	for(i = 1; i < n; i++)
	{
		toInsert = v[i]; //elemento a inserir
		j=i;
		while (toInsert < v[j-1] && j > 0) //procura onde inserir
		{
			v[j] = v[j-1];
			j--;
		}
		v[j] = toInsert;
	}
}


void quicksort(int *v, int inicio, int fim) {
	int pivo = v[ (int)(inicio+fim)/2 ];
	int i = inicio, j = fim, temp;
	while (i < j) {
		while(pivo > v[i]) i++;
		while(pivo < v[j]) j--;
		if (i<=j) {
			temp = v[i];
			v[i] = v[j];
			v[j] = temp;
			i++;
			j--;
		}
	}
	if (j > inicio)
      quicksort(v, inicio, j);
	if (i < fim)
      quicksort(v, i, fim);
}
