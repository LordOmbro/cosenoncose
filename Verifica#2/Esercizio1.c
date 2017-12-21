#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 30

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
	tipodato dato;
	struct EL *next;
} tipoelemento;

typedef tipoelemento *tipolista;

void _inizializza(tipolista *lista);
bool _isEnd(tipolista lista);
void _inserisci_dati(tipolista *lista)
void _inserisci(tipolista *lista, tipodato dati);
void _elimina_testa(tipolista *lista);
void _elimina_posizione(tipolista *lista);
void _stampa(tipolista lista);
void _media(tipolista lista);

int main(){
	tipolista lista;
	int sel,id;
	_inizializza(&lista);
	while(true){
		printf("\nMENU\n");
		printf("1. Inserisci prenotazione\n");
		printf("2. Elimina prenotazione\n");
		printf("3. Stampa prenotazione in attesa\n");
		printf("4. Calcola importo medio per prenotazione\n");
		printf("\n0. Inserisci prenotazione\n");
		printf("\nSelezione: ");
		scanf("%d",&sel);
		switch(sel){
			case 0:
				printf("\nNegozio chiuso!\n");
				break;
			case 1:
				_inserisci_dati(&lista);
				break;
			case 2:
				// SOTTOMENU: elimina testa o in mezzo -- NON NECESSARIO
				system("clear");
				printf("\nSOTTOMENU: ELIMINAZIONE\n");
				printf("1. Elimina prenotazione più vecchia\n");
				printf("2. Elimina prenotazione per ID\n");
				printf("\n0. Torna al menu principale\n");
				printf("\nSelezione: \n");
				scanf("%d",&sel);
				switch(sel){
					case 1:
						break;
					case 2:
						break;
					default:
						break;
				}
				break;
			case 3:
				break;
			case 4:
				break;
			default:
				printf("Selezione non valida\n");
				break;
		}
		printf("\nPremi ENTER per tornare al menu\n");
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
