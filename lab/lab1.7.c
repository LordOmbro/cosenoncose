#include <stdio.h>
#define pi 3.14
#define true 1
float _cerchio(){
	float r;
	printf("Inserisci il raggio: ");
	scanf("%f",&r);
	return pi*r*r;
}
float _cilindro(){
	float r,h;
	printf("Inserisci il raggio: ");
	scanf("%f",&r);
	printf("Inserisci l'altezza: ");
	scanf("%f",&h);
	return 2*pi*r*r+2*pi*r*h;
}
int main(){
	int sel;
	do {
		printf("\nMENU\n");
		printf("1. Calcola area del cerchio\n");
		printf("2. Calcola area della sfera\n");
		printf("3. Calcola area del cilindro\n");
		printf("\n0. Esci dal programma\n");
		printf("\nSelezione: ");
		scanf("%d",&sel);
		switch(sel){
			case 0:
				return 0;
				break;
			case 1:
				printf("Risultato: %.2f",_cerchio());
				break;
			case 2:
				printf("Risultato: %.2f",4*_cerchio());
				break;
			case 3:
				printf("Risultato: %.2f",_cilindro());
				break;
			default:
				printf("Selezione non valida\n");
				break;
		}
	} while(true);
}
