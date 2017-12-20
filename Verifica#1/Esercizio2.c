#include <stdio.h>
#define LEN_MAX 30
#define MAX 50
#define true 1
typedef char str[LEN_MAX];
typedef struct PERSONA {
	str cognome;
	str nome;
	struct DATA {
		int short giorno;
		int short mese;
		int short anno;
	} data;
	float reddito;
} persona;

persona _inserisci(){
	persona tmp;
	printf("Cognome: ");
	scanf("%s",tmp.cognome);	//%s non supporta gli spazi, ma evito ciclo for con scanf char per char
	printf("Nome: ");
	scanf("%s",tmp.nome);
	printf("Data di nascita [gg mm aaaa]: ");
	scanf("%d%d%d",&tmp.data.giorno,&tmp.data.mese,&tmp.data.anno);
	printf("Reddito lordo all'ultima dichiarazione: €");
	scanf("%f",&tmp.reddito);
	return tmp;
}

void _stampa(persona tmp,int i){
	printf("\nPERSONA #%d:\n",i+1);
	printf("Nome: %s %s\n",tmp.cognome,tmp.nome);
	printf("Data di nascita: %d/%d/%d\n",tmp.data.giorno,tmp.data.mese,tmp.data.anno);
	printf("Reddito lordo all'ultima dichiarazione: €%.2f\n",tmp.reddito);
}

void _stampa_reddito(persona tmp[],int cont){
	int i;
	float max=tmp[0].reddito;
	for(i=1;i<cont;i++)
		if(tmp[i].reddito>max){
			max=tmp[i].reddito;
		}
	printf("Persone con il reddito più alto:\n");
	for(i=0;i<cont;i++)
		if(tmp[i].reddito==max)
			_stampa(tmp[i],i);	
}

float _somma(persona tmp[],int cont,int i){
	if(i<cont)
		return tmp[i].reddito+_somma(tmp,cont,i+1);
	return 0;
}

void _cerca(persona tmp[],int cont){
	int min=1,max=0,i;
	while(max<min){
		printf("Inserisci anno minimo: ");
		scanf("%d",&min);
		printf("Inserisci anno massimo: ");
		scanf("%d",&max);
		if(max<min)
			printf("La data massima (%d) è superiore alla minima indicata (%d)!\n",max,min);
	}
	printf("\nPersone corrispondenti ai criteri di ricerca:\n");	//nessun algoritmo di sorting, in ordine di
	for(i=0;i<cont;i++)												//apparizione nell'archivio e non di data
		if(tmp[i].data.anno>=min&&tmp[i].data.anno<=max)
			_stampa(tmp[i],i);
}

int main(){
persona archivio[MAX];
int sel,i,cont=0;
while(true) {
	printf("--------\n+-MENU-+\n--------\n");
	printf("1. Inserisci dati anagrafici\n");
	printf("2. Visualizza dati inseriti\n");
	printf("3. Visualizza reddito più alto\n");
	printf("4. Visualizza reddito medio\n");
	printf("5. Ricerca per data\n");
	printf("\n0. Esci dal programma\n");
	printf("\nSelezione: ");
	scanf("%d",&sel);
	switch(sel){
		case 0:
			return 0;
			break;
		case 1:
			if(cont<MAX){
				archivio[cont]=_inserisci();
				cont++;
			}
			else
				printf("Numero massimo di persone raggiunto!\n");
			break;
		case 2:
			for(i=0;i<cont;i++)
				_stampa(archivio[i],i);
			break;
		case 3:
			_stampa_reddito(archivio,cont);
			break;
		case 4:
			printf("Media dei redditi inseriti: €%.2f",_somma(archivio,cont,0)/cont);
			break;
		case 5:
			_cerca(archivio,cont);
			break;
		default:
			printf("Selezione non valida\n");
			break;
		}
	printf("\nPremi ENTER per tornare al menu..\n");
	system("read p");
	system("clear");
	}
}