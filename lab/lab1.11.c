#include <stdio.h> <time.h> <stdlib.h>
float prodotto(int n,int matr[n][n],int i){
	if(i<n)
		return matr[i][i]*prodotto(n,matr,i+1);
	else
		return 1;
}
void main(){
	int n,i,j;
	printf("Quanto la vuoi grande la matrice? ");
	scanf("%d",&n);
	int matr[n][n];
	srand(time(NULL));
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			matr[i][j]=rand()%9+1;
			printf("%d ",matr[i][j]);
		}
		printf("\n");
	}
	printf("Il prodotto degli elementi sulla diagonale è %.0f\n",prodotto(n,matr,0));
}