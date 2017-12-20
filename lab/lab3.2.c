#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 30

typedef enum {false,true} bool;
typedef char str[MAX_LEN];
struct DATA {
	int giorno;
	int mese;
	int anno;
};

typedef struct DATO {
	str cognome;
	str nome;
	struct DATA data;
	float importo;
} tipodato;

typedef struct EL {
	tipodato persona;
	struct EL *next;
} tipoelemento;
typedef tipoelemento *tipolista;

void _inizializza(tipolista *lista);
bool _isEnd(tipolista lista);
void _leggi_dati(tipolista *lista, int sel);
void _inserisci_testa(tipolista *lista,tipodato dati);
void _inserisci_coda(tipolista *lista,tipodato dati);
float _stampa_tot(tipolista lista);
int _media(tipolista lista,str cerca_cognome,str cerca_nome);
int _cont(tipolista lista,str cerca_cognome,str cerca_nome);
void _carica(tipolista *lista);

int main(){
	tipolista lista;
	int sel;
	str cerca_cognome,cerca_nome;
	_inizializza(&lista);
	_carica(&lista);
	while(true){
		printf("1. Inserisci in testa\n");
		printf("2. Inserisci in coda\n");
		printf("3. Stampa totale movimenti\n");
		printf("4. Stampa media movimenti dato nominativo\n");
		printf("\n0. Esci dal programma\n");
		printf("\nSelezione: ");
		scanf("%d",&sel);
		switch(sel){
			case 0:
				printf("Arrivederci!\n");
				return 0;
				break;
			case 1: case 2:
				_leggi_dati(&lista,sel);
				break;
			case 3:
				printf("Tot: %.2f",_stampa_tot(lista));
				break;
			case 4:
				printf("Cognome Nome: ");
				scanf(" %s",cerca_cognome);
				scanf(" %s",cerca_nome);
				printf("\nLa media delle transazioni di %s %s è %.2f",cerca_cognome,cerca_nome,(float)_media(lista,cerca_cognome,cerca_nome)/_cont(lista,cerca_cognome,cerca_nome));
				break;
			default:
				printf("Selezione non valida!\n");
				break;
		}
		printf("\nPremi ENTER per tornare al menu..\n");
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
	else
		return false;
}

void _leggi_dati(tipolista *lista, int sel){
	tipodato dati;
	printf("Cognome: ");
	scanf("%s",dati.cognome);
	printf("Nome: ");
	scanf("%s",dati.nome);
	printf("Data di nascita [gg mm aaaa]: ");
	scanf("%d%d%d",&dati.data.giorno,&dati.data.mese,&dati.data.anno);
	printf("Importo: ");
	scanf("%f",&dati.importo);
	if(sel==1)
		_inserisci_testa(lista,dati);
	else if(sel==2)
		_inserisci_coda(lista,dati);
	else
		printf("Questo errore non sarebbe mai dovuto comparire. L'informatica è rotta!");
}

void _inserisci_testa(tipolista *lista, tipodato dati){
	tipoelemento *punt;
	punt=malloc(sizeof(tipoelemento));
	punt->persona=dati;
	punt->next=*lista;
	*lista=punt;
}

void _inserisci_coda(tipolista *lista, tipodato dati){
	tipolista punt;
	if(_isEnd(*lista)){
		punt=malloc(sizeof(tipoelemento));
		punt->persona=dati;
		punt->next=NULL;
		*lista=punt;
	}
	else
		_inserisci_coda(&(*lista)->next,dati);
}

float _stampa_tot(tipolista lista){
	if(_isEnd(lista))
		return 0;
	else
		return lista->persona.importo+_stampa_tot(lista->next);
}

int _media(tipolista lista, str cerca_cognome, str cerca_nome){
	if(_isEnd(lista))
		return 0;
	if(strcmp(lista->persona.cognome,cerca_cognome)==0&&strcmp(lista->persona.nome,cerca_nome)==0)
		return lista->persona.importo+_media(lista->next,cerca_cognome,cerca_nome);
	else
		return _media(lista->next,cerca_cognome,cerca_nome);
	}

	int _cont(tipolista lista, str cerca_cognome, str cerca_nome){
	if(_isEnd(lista))
		return 0;
	if(strcmp(lista->persona.cognome,cerca_cognome)==0&&strcmp(lista->persona.nome,cerca_nome)==0)
		return 1+_cont(lista->next,cerca_cognome,cerca_nome);
	return 0+_cont(lista->next,cerca_cognome,cerca_nome);
}

void _carica(tipolista *lista){
	int i,n;
	tipodato dati;
	printf("Numero elementi da caricare: ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		switch(rand()%5){
			case 0:
				strcpy(dati.nome,"Gianmario");
				strcpy(dati.cognome,"Rossi");
				dati.data.giorno=12;
				dati.data.mese=12;
				dati.data.anno=1976;
				dati.importo=(float)rand()/7;
				break;
			case 1:
				strcpy(dati.nome,"Annamaria");
				strcpy(dati.cognome,"Verdi");
				dati.data.giorno=4;
				dati.data.mese=9;
				dati.data.anno=1996;
				dati.importo=(float)rand()/7;
				break;
			case 2:
				strcpy(dati.nome,"Carlo");
				strcpy(dati.cognome,"Bianchi");
				dati.data.giorno=29;
				dati.data.mese=2;
				dati.data.anno=1987;
				dati.importo=(float)rand()/7;
				break;
			case 3:
				strcpy(dati.nome,"Lucia");
				strcpy(dati.cognome,"Gialli");
				dati.data.giorno=19;
				dati.data.mese=11;
				dati.data.anno=1980;
				dati.importo=(float)rand()/7;
				break;
			default:
				strcpy(dati.nome,"Antonella");
				strcpy(dati.cognome,"Rosa");
				dati.data.giorno=10;
				dati.data.mese=11;
				dati.data.anno=1966;
				dati.importo=(float)rand()/7;
				break;
		}
		_inserisci_coda(lista,dati);
	}
}
