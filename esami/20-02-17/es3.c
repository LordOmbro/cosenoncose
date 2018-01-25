#include <stdio.h>
#include <stdlib.h>
#define MAX 10

//TESTO DELLA CONSEGNA 3
struct elem {
int num;
struct elem *prox;
};
typedef struct elem elemLista;
typedef elemLista *lista;

//CONSEGNA 1
int _array(int *array, int n){
	if(n==0){
		if(array[0]>5 && array[0]%2==0)
			return 1;
		else
			return 0;
	}
	if(array[0]>5 && array[0]%2==0)
		return 1+_array(&array[1],n-1);
	return _array(&array[1],n-1);
}

//CONSEGNA 2
int _power(int a, int b){
	if(b==0)
		return 1;
	return a*_power(a,b-1);
}

//CONSEGNA 3
int _lista(lista numeri){
	if(numeri->prox==NULL)
		return 0;
	if(numeri->num%3==0 || numeri->num%5==0)
		return _lista(numeri->prox);
	return 1+_lista(numeri->prox);
}

//UN MAIN PER VERIFICARE CHE IL PROGRAMMA FUNZIONI!!!
void _carica(lista *numeri, int array[MAX]){
	int i;
	for(i=0;i<MAX;i++){
		lista punt;
		punt=malloc(sizeof(elemLista));
		punt->num=array[i];
		punt->prox=*numeri;
		*numeri=punt;
	}
}

int main(){
	int array[MAX]={2,55,3,5,77,3,5,534,7,9},a=5,b=3;
	lista numeri;
	numeri=NULL;
	_carica(&numeri,array);
	printf("Array: %d",_array(array,MAX-1));
	printf("\nPower: %d",_power(a,b));
	printf("\nLista: %d",_lista(numeri));
}
