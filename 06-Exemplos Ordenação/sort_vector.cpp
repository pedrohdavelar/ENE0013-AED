#include "sort_vector.h"

void bubblesort(std::vector<int> &v){
	int i, j, temp, troca = 1;

	for(i = v.size()-1; troca && i > 0; i--){
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

void selectionsort(std::vector<int> &v)
{
	int k, i, pmenor, tmp;
	for (k=0; k<v.size()-1; k++)
	{
		pmenor = k;
		for(i=k+1; i<v.size(); i++)
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

void insertionsort(std::vector<int> &v)
{
	int i, j, toInsert;
	for(i = 1; i < v.size(); i++)
	{
		toInsert = v[i]; //elemento a inserir
		j = i;
		while (toInsert < v[j-1] && j > 0) //procura onde inserir
		{
			v[j] = v[j-1];
			j--;
		}
		v[j] = toInsert;
	}
}


void quicksort(std::vector<int> &v, int inicio, int fim) {
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
