#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 30

typedef char str[MAX_LEN];
typedef enum {false,true} bool;

typedef struct SP{
	str nome;
	char genere;
	int h;
} tipopersona;

typedef struct SE{
	tipopersona persona;
	struct SE *next;
} tipoelemento;
typedef tipoelemento *tipolista;

void inizializza(tipolista *lista);
bool isEnd(tipolista lista);
void _append(tipolista *lista, tipopersona dati);
void _affix(tipolista *lista, tipopersona dati);
void _inserisci(tipolista *lista, int sel);
void _del_head(tipolista *lista);
void _del_bottom(tipolista *lista);
void _stampa(tipolista lista);
int _media(tipolista lista);
int _cont(tipolista lista);
int _percentuale(tipolista lista);

int main(){
	tipolista lista;
	int sel,n=0,i;
	inizializza(&lista);
	while(true){
		printf("\nMENU\n");
		printf("1. Stampa dati nella lista\n");
		printf("2. Altezza media\n");
		printf("3. Percentuale genere\n");
		printf("4. Inserisci in testa\n");
		printf("5. Inserisci in coda\n");
		printf("6. Cancella testa\n");
		printf("7. Cancella in coda\n");
		printf("\n0. Esci dal programma\n");
		printf("\nSelezione: ");
		scanf("%d",&sel);
		switch(sel){
			case 0:
				return 0;
				break;
			case 1:
				_stampa(lista);
				break;
			case 2:
				printf("Media altezze: %dcm",_media(lista)/_cont(lista));
				break;
			case 3:
				if(_percentuale>=0){
					printf("Donne: %d\%\n",_percentuale(lista));
					printf("Uomini: %d\%\n",100-_percentuale(lista));
				}
				else
					printf("Lista vuota!");
				break;
			case 4: case 5:
				_inserisci(&lista,sel);
				break;
			case 6:
				_del_head(&lista);
				_stampa(lista);
				break;
			case 7:
				_del_bottom(&lista);
				_stampa(lista);
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

void inizializza(tipolista *lista){
	*lista=NULL;
}

bool isEnd(tipolista lista){
	if(lista==NULL)
		return true;
	else
		return false;
}

void _inserisci(tipolista *lista, int sel){
	tipopersona dati;
	printf("Nome: ");
	scanf("%s",dati.nome);
	scanf("%c",&dati.genere);
	printf("Genere: ");
	scanf("%c",&dati.genere);
	while(dati.genere!='m' && dati.genere!='f'){
		printf("NON VALIDO! Genere (m/f): ");
		scanf("%c",&dati.genere);
	}
	printf("Altezza: ");
	scanf("%d",&dati.h);
	if(sel==4)
		_affix(lista,dati);
	else
		_append(lista,dati);
}

void _append(tipolista *lista, tipopersona dati){
	tipoelemento *punt;
	if(isEnd(*lista)){
		punt=malloc(sizeof(tipoelemento));
		punt->persona=dati;
		punt->next=NULL;
		*lista=punt;
	}
	else
		_append(&(*lista)->next,dati);	
}

void _affix(tipolista *lista, tipopersona dati){
	tipoelemento *punt;
	punt=malloc(sizeof(tipoelemento));
	punt->persona=dati;
	punt->next=*lista;
	*lista=punt;
}

void _stampa(tipolista lista){
	if(isEnd(lista))
		return;
	else {
		if(lista->persona.genere=='f')
			printf("Sig.ra ");
		else
			printf("Sig.   ");
		printf("%s: %dcm\n",lista->persona.nome,lista->persona.h);
		_stampa(lista->next);
	}
}

int _media(tipolista lista){
	if(isEnd(lista))
		return 0;
	else
		return lista->persona.h + _media(lista->next);
}

int _cont(tipolista lista){
	if(isEnd(lista))
		return 0;
	else
		return 1+_cont(lista->next);
}

void _del_head(tipolista *lista){
	if(isEnd(*lista)){
		printf("La lista è vuota!");
		return;
	}
	printf("VOCE RIMOSSA: %s, %c, %dcm\nRimanenti:\n",(*lista)->persona.nome,(*lista)->persona.genere,(*lista)->persona.h);
	*lista=(*lista)->next;
}

void _del_bottom(tipolista *lista){
	if(isEnd(*lista)){
		printf("La lista è vuota!");
		return;
	}
	if(isEnd((*lista)->next)){
		printf("VOCE RIMOSSA: %s, %c, %dcm\nRimanenti:\n",(*lista)->persona.nome,(*lista)->persona.genere,(*lista)->persona.h);
		*lista=NULL;
	}
	else
		_del_bottom(&(*lista)->next);
}

int _cont_f(tipolista lista){
	if(isEnd(lista))
		return 0;
	else if(lista->persona.genere=='f')
		return 1+_cont_f(lista->next);
	else
		return 0+_cont_f(lista->next);
}

int _percentuale(tipolista lista){
	if(_cont(lista)>0)
		return 100*_cont_f(lista)/_cont(lista);
	return -1;
}