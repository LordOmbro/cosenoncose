#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_LEN 30
#define MAX_ARTICOLI 10

typedef char str[MAX_LEN];
typedef enum {false,true} bool;

typedef struct DATA {
	int giorno;
	int mese;
	int anno;
	int h;
	int m;
} tipodata;

typedef struct DATO {
	int id;
	tipodata data;
	int articoli;
	float importo;
} tipodato;

typedef struct EL {
	tipodato dati;
	struct EL *next;
} tipoelemento;

typedef tipoelemento *tipolista;

void _inizializza(tipolista *lista);
bool _isEnd(tipolista lista);
void _inserisci_dati(tipolista *lista, int id);
void _inserisci(tipolista *lista, tipodato dati);
void _elimina_testa(tipolista *lista);
void _elimina_posizione(tipolista *lista);
void _stampa_tutto(tipolista lista);
void _stampa(tipolista lista);
float _media(tipolista lista);
int _cont(tipolista lista);

int main(){
	tipolista lista;
	int sel,id=0;
	_inizializza(&lista);
	system("clear");

	system("clear");
	while(true){
		printf("\nMENU\n");
		printf("1. Inserisci prenotazione\n");
		printf("2. Elimina prenotazione\n");
		printf("3. Stampa prenotazioni in attesa\n");
		printf("4. Calcola importo medio per prenotazione\n");
		printf("\n0. Esci dal programma\n");
		printf("\nSelezione: ");
		scanf("%d",&sel);
		switch(sel){
			case 0:
				printf("Negozio chiuso!\n");
				return 0;
				break;
			case 1:
				id++;
				_inserisci_dati(&lista,id);
				break;
			case 2:
				// SOTTOMENU: elimina testa o in mezzo -- NON NECESSARIO
				if(_isEnd(lista)){
					printf("Nessuna prenotazione!\n");
					break;
				}
				system("clear");
				printf("\nSOTTOMENU: ELIMINAZIONE\n");
				printf("1. Elimina prenotazione più vecchia\n");
				printf("2. Elimina prenotazione per ID\n");
				printf("\n0. Torna al menu principale\n");
				printf("\nSelezione: ");
				scanf("%d",&sel);
				switch(sel){
					case 1:
						_elimina_testa(&lista);
						break;
					case 2:
						_elimina_posizione(&lista);
						break;
					default:
						break;
				}
				break;
			case 3:
				_stampa_tutto(lista);
				break;
			case 4:
				if(_cont(lista)!=0)
					printf("\nL'importo medio delle prenotazioni in attesa è €%.2f\n",_media(lista)/(float)_cont(lista));
				else
					printf("\nNessuna prenotazione in attesa\n");
				break;
			default:
				printf("\nSelezione non valida\n");
				break;
		}
		printf("Premere ENTER per tornare al menu\n");
		system("read");
		system("clear");
	}
}

void _inizializza(tipolista *lista){
	*lista=NULL;
}

bool _isEnd(tipolista lista){
	if(lista==NULL)
		return true;
	return false;
}

void _inserisci_dati(tipolista *lista, int id){
	tipodato dati;
	time_t t=time(NULL);
	struct tm *data_ora=localtime(&t);
	dati.id=id;
	dati.data.giorno=data_ora->tm_mday;
	dati.data.mese=data_ora->tm_mon+1;
	dati.data.anno=data_ora->tm_year+1900;
	dati.data.h=data_ora->tm_hour;
	dati.data.m=data_ora->tm_min;
	printf("Numero articoli: ");
	scanf("%d",&dati.articoli);
	while(dati.articoli<1||dati.articoli>10){
		printf("Numero di articoli non valido [MAX %d]: ",MAX_ARTICOLI);
		scanf("%d",&dati.articoli);
	}
	printf("Totale: €");
	scanf("%f",&dati.importo);
	while(dati.importo<=0){
		printf("Importo non valido, riprova: ");
		scanf("%f",&dati.importo);
	}
	_inserisci(lista,dati);
}

void _inserisci(tipolista *lista, tipodato dati){
	tipolista punt;
	if(_isEnd(*lista)){
		punt=malloc(sizeof(tipoelemento));
		punt->dati=dati;
		punt->next=NULL;
		*lista=punt;
		return;
	}
	_inserisci(&(*lista)->next,dati);
}

void _elimina_testa(tipolista *lista){
	tipolista punt;
	punt=*lista;
	if(_isEnd(*lista)){
		printf("Nessuna prenotazione!");
		return;
	}
	printf("PRENOTAZIONE RIMOSSA: ");
	_stampa(*lista);
	*lista=(*lista)->next;
	free(punt);
}

void _elimina_posizione(tipolista *lista){
	tipolista puntCorrente,puntPrecedente;
	int id_el;
	puntPrecedente=NULL;
	puntCorrente=*lista;
	printf("ID prenotazione da eliminare: ");
	scanf("%d",&id_el);
	if(puntCorrente->dati.id==id_el){
		_elimina_testa(lista);
		return;
	}
	while(_isEnd(puntCorrente)==false){
		if(puntCorrente->dati.id==id_el)
			break;
		puntPrecedente=puntCorrente;
		puntCorrente=puntCorrente->next;
	}
	if(_isEnd(puntCorrente)){
		printf("L'ID %d non esiste!\n",id_el);
		return;
	}
	puntPrecedente->next=puntCorrente->next;
	printf("PRENOTAZIONE RIMOSSA: ");
	_stampa(puntCorrente);
	free(puntCorrente);
}

void _stampa_tutto(tipolista lista){
	int i=0;
	printf("\n");
	while(_isEnd(lista)==false){
		i++;
		_stampa(lista);
		lista=lista->next;
	}
	printf("Prenotazioni in attesa: %d\n",i);
}

void _stampa(tipolista lista){
	printf("N.%d %d/%d/%d %d.%d: %d elementi, €%.2f\n",	lista->dati.id,
														lista->dati.data.giorno,
														lista->dati.data.mese,
														lista->dati.data.anno,
														lista->dati.data.h,
														lista->dati.data.m,
														lista->dati.articoli,
														lista->dati.importo
	);
}

float _media(tipolista lista){
	if(_isEnd(lista))
		return 0;
	return lista->dati.importo+_media(lista->next);
}

int _cont(tipolista lista){
	if(_isEnd(lista))
		return 0;
	return 1+_cont(lista->next);
}
