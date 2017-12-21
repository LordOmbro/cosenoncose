#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_LEN 30
#define MAX_ARTICOLI 10

typedef char str[MAX_LEN];
typedef enum {false,true} bool;

typedef struct DATA {
	int giorno;
	int mese;
	int anno;
} tipodata;

typedef struct ORA {
	int h;
	int m;
} tipoora;

typedef struct DATO {
	int id;
	tipodata data;
	tipoora ora;
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
void _inserisci_dati(tipolista *lista, int id, tipodata data_oggi);
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
	tipodata data_oggi;
	_inizializza(&lista);
	printf("\nInserisci la data di lavoro [gg mm aaaa]: "); //SICCOME IL PROGRAMMA VIENE RIAVVIATO OGNI GIORNO, IMMAGINO CHE PER TUTTA LA DURATA DEL PROGRAMMA RIMANGA INVARIATA
	scanf("%d%d%d",&data_oggi.giorno,&data_oggi.mese,&data_oggi.anno);
	while(true){
		printf("\nMENU\n");
		printf("1. Inserisci prenotazione\n");
		printf("2. Elimina prenotazione\n");
		printf("3. Stampa prenotazioni in attesa\n");
		printf("4. Calcola importo medio per prenotazione\n");
		printf("\n0. Inserisci prenotazione\n");
		printf("\nSelezione: ");
		scanf("%d",&sel);
		switch(sel){
			case 0:
				printf("\nNegozio chiuso!\n");
				return 0;
				break;
			case 1:
				id++;
				_inserisci_dati(&lista,id,data_oggi);
				break;
			case 2:
				// SOTTOMENU: elimina testa o in mezzo -- NON NECESSARIO
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
				printf("\nL'importo medio delle prenotazioni in attesa è €%.2f\n",_media(lista)/(float)_cont(lista));
				break;
			default:
				printf("\nSelezione non valida\n");
				break;
		}
		printf("\nPremi ENTER per tornare al menu\n");
		system("read p");
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

void _inserisci_dati(tipolista *lista, int id, tipodata data_oggi){
	tipodato dati;
	time_t t;
	struct tm *ora_corrente=localtime(&t);
	dati.id=id;
	dati.data.giorno=data_oggi.giorno;
	dati.data.mese=data_oggi.mese;
	dati.data.anno=data_oggi.anno;
	dati.ora.h=ora_corrente->tm_hour;
	dati.ora.m=ora_corrente->tm_min;
	printf("\nNumero articoli: ");
	scanf("%d",&dati.articoli);
	while(dati.articoli<1||dati.articoli>10){
		printf("Numero di articoli non valido [MAX %d]: ",MAX_ARTICOLI);
		scanf("%d",&dati.articoli);
	}
	printf("\nTotale: ");
	scanf("%f",&dati.importo);
	while(dati.importo<=0){
		printf("Importo non valido, riprova: ");
		scanf("%d",&dati.articoli);
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
	tipoelemento *puntCorrente,*puntPrecedente;
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
		printf("Posizione non valida");
		return;
	}
	puntPrecedente->next=puntCorrente->next;
	printf("PRENOTAZIONE RIMOSSA: ");
	_stampa(puntCorrente);
	free(puntCorrente);
}

void _stampa_tutto(tipolista lista){
	int i=0;
	while(_isEnd(lista)==false){
		i++;
		_stampa(lista);
		lista=lista->next;
	}
	printf("\nPrenotazioni in attesa: %d\n",i);
}

void _stampa(tipolista lista){
	printf("N.%d %d/%d/%d %d.%d: %d elementi, €%.2f\n",	lista->dati.id,
														lista->dati.data.giorno,
														lista->dati.data.mese,
														lista->dati.data.anno,
														lista->dati.ora.h,
														lista->dati.ora.m,
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
