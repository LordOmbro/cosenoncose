#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 8
#define NUM_MIN 5
#define NUM_MAX 30

float _prodotto(int n,int matr[n][n],int i){
	if(i<n)
		return matr[i][i]*_prodotto(n,matr,i+1);
	return 1;
}

int main(){
	int n,i,j;
	srand(time(NULL));
	printf("Dimensione matrice [2-%d]: ",MAX);
	scanf("%d",&n);
	while(n<2||n>MAX){
		printf("Dimensione non valida, riprova [2-%d]: ",MAX);
		scanf("%d",&n);
	}
	int matr[n][n];
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			matr[i][j]=rand()%(NUM_MAX-NUM_MIN+1)+NUM_MIN;
			if(matr[i][j]<10)
				printf("0%d ",matr[i][j]);
			else
				printf("%d ",matr[i][j]);
		}
		printf("\n");
	}
	printf("\nProdotto dei numeri sulla diagonale principale: %.0f\n",_prodotto(n,matr,0));
	return 0;
}
//FINE - punti: 0,5+
