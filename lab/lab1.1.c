#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
#define NUM_MAX
#define NUM_MIN
int random=rand()%(NUM_MAX-NUM_MIN+1)+NUM_MIN
*/
float tot[4];
void stampa(float m[4][6]) {
	int i,j;
	for(i=0;i<4;i++) {
		printf("\n");
		for(j=0;j<6;j++)
			if(m[i][j]<10)
				printf("  %.3f",m[i][j]);
			else
				printf(" %.3f",m[i][j]);
	}
	printf("\n\n");
}
float somma(float m[4][6], int j) {
	int i;
	for(i=0;i<4;i++)	//per ogni riga della colonna
		tot[j]+=m[i][j];	//somma elementi
	return tot[j];
}
int main() {
	int i,j;
	float m[4][6];
	//POPOLA LA MATRICE A RANDOM
	srand(time(NULL));	//CREDO FACCIA IL SEED
	for(i=0;i<4;i++)	//per ogni riga
		for(j=0;j<6;j++)	//per ogni colonna
			m[i][j]=(int)rand()/(float)rand();	//imposta numero casuale
	//FUNZIONI
	stampa(m);
	for(j=0;j<6;j++)	//per ogni colonna
		printf("Totale colonna %d: %f, media: %f\n",j+1,somma(m,j),somma(m,j)/4);	//stampa totale e media colonna
	return 0;
}