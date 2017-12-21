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
void _inserisci_coda(tipolista *lista, tipodato dati);
void _inserisci_testa(tipolista *lista, tipodato dati);
void _inserisci_testa(tipolista *lista, tipodato dati);
void _elimina_posizione(tipolista *lista);
void _stampa(tipolista lista);
void _media(tipolista lista);

int main(){
	tipolista lista;
	int sel;
	_inizializza(&lista);
	while(true){
		printf("\nMENU\n");
		printf("1. Inserisci prenotazione\n");
		printf("2. Elimina prenotazione\n");
		printf("3. Stampa prenotazione in attesa\n");
		printf("4. Calcola importo medio per prenotazione\n");
		printf("\n0. Inserisci prenotazione\n");
		printf("\nSelezione: ");



	}
}
