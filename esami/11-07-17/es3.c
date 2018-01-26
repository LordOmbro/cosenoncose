#include <stdio.h>
#define MAX 10
/* `&array[1]` e `array+1` sono la stessa cosa!! */

//CONSEGNA 1
int contatore(int array[], int n, int primo){
	if(n==0)
		return (array[0]%primo==0);
	return (array[0]%primo==0)+contatore(&array[1],n-1,primo);
}

//CONSEGNA 2
int specchio(int array[], int n){
	if(n==0||n==1)
		return 1;
	return (array[0]%array[n-1]==0) && specchio(array+1,n-2);
}

//CONSEGNA 3
int sommalista(lista l){
	if(l==NULL)
		return 0;
	if(l->num % 2 == 0)
		return l->num + sommalista(l->prox->prox);
}

//chiamata: sommalista(lista)

int main(){
	int array[MAX]={10,10,10,10,10,5,5,5,2,2};
	printf("%d -- %d",contatore(array,MAX-1,array[0]),specchio(array,MAX));
	return 0;
}
