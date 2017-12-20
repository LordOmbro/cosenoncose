#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

void _inizializza(tipolista *lista);
bool _isEnd(tipolista lista);
void _inserisci_coda(tipolista *lista, tipopersona dati);
void _inserisci_testa(tipolista *lista, tipopersona dati);
void _inserisci_posizione(tipolista *lista, tipopersona dati);
void _leggi_dati(tipolista *lista, int sel);
void _elimina_testa(tipolista *lista);
void _elimina_coda(tipolista *lista,tipolista puntPrecedente);
void _elimina_posizione(tipolista *lista);
void _stampa_tutto(tipolista lista, int i);
void _stampa(tipolista lista);
void _cerca(tipolista lista);
int _media(tipolista lista);
int _cont(tipolista lista);
float _percentuale(tipolista lista);
int _cont_f(tipolista lista);

int main(){
	tipolista lista;
	int sel,nop=0;
	char cerr;
	_inizializza(&lista);
	while(true){
		printf("\nMENU PRINCIPALE\n");
		printf("1. Stampa dati nella lista\n");
		printf("2. Analizza dati\n");
		printf("3. Inserisci dati\n");
		printf("4. Rimuovi dati\n");
		printf("5. Cerca per nome\n");
		printf("\n0. Esci dal programma\n");
		printf("\nSelezione: ");
		scanf("%d",&sel);
		scanf("%c",&cerr);
		if(cerr!='\n'){
			sel=-1;
		}
		switch(sel){
			case 0:
				return 0;
				break;
			case 1:
				_stampa_tutto(lista,1);
				break;
			case 2:
				if(_isEnd(lista)){
				   printf("\nLa lista è vuota, nessun dato da analizzare!\n");
				   break;
				}
				system("clear");
				printf("\n--> MENU ANALISI DATI\n");
				printf("1. Altezza media\n");
				printf("2. Percentuale genere\n");
				printf("\n0. Torna al menu principale\n");
				printf("\nSelezione: ");
				scanf("%d",&sel);
				switch(sel){
					case 0:
						nop=1;
						break;
					case 1:
						printf("Media altezze: %.1fcm",(float)_media(lista)/_cont(lista));
						break;
					case 2:
						if(_percentuale>=0){
							printf("Donne: %.1f%%\n",_percentuale(lista));
							printf("Uomini: %.1f%%\n",100-_percentuale(lista));
						}
						break;
					default:
						printf("Selezione non valida\n");
						break;
				}
				break;
			case 3:
				system("clear");
				printf("\n--> MENU INSERIMENTO DATI\n");
				printf("1. Inserisci in testa\n");
				printf("2. Inserisci in coda\n");
				printf("3. Inserisci in posizione\n");
				printf("\n0. Torna al menu principale\n");
				printf("\nSelezione: ");
				scanf("%d",&sel);
				switch(sel){
					case 0:
						nop=1;
						break;
					case 1: case 2: case 3:
						_leggi_dati(&lista,sel);
						break;
					default:
						printf("Selezione non valida\n");
						break;
				}
				break;
			case 4:
				system("clear");
				printf("\n--> MENU RIMOZIONE DATI\n");
				printf("1. Rimuovi in testa\n");
				printf("2. Rimuovi in coda\n");
				printf("3. Rimuovi in posizione\n");
				printf("4. Rimuovi tutto\n");
				printf("\n0. Torna al menu principale\n");
				printf("\nSelezione: ");
				scanf("%d",&sel);
				switch(sel){
					case 0:
						nop=1;
						break;
					case 1:
						_elimina_testa(&lista);
						break;
					case 2:
						_elimina_coda(&lista,NULL);
						break;
					case 3:
						_elimina_posizione(&lista);
						break;
					case 4:
						while(_isEnd(lista)==false)
							_elimina_testa(&lista);
						break;
					default:
						printf("Selezione non valida\n");
						break;
				}
				break;
			case 5:
				_cerca(lista);
				break;
			default:
				printf("Selezione non valida\n");
				break;
		}
		if(nop==0){
			printf("\nPremi ENTER per tornare al menu..\n");
			system("read p");
		}
		system("clear");
		nop=0;
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

void _stampa_tutto(tipolista lista,int i){
	if(_isEnd(lista))
		return;
	else {
		printf("%d. ",i);
		_stampa(lista);
		_stampa_tutto(lista->next,i+1);
	}
}

void _stampa(tipolista lista){
	if(lista->persona.genere=='f')
		printf("Sig.ra ");
	else
		printf("Sig.   ");
	printf("%s: %dcm\n",lista->persona.nome,lista->persona.h);
}

void _leggi_dati(tipolista *lista, int sel){
	tipopersona dati;
	printf("Nome: ");
	scanf("%s",dati.nome);
	scanf("%c",&dati.genere);
	printf("Genere: ");
	scanf("%c",&dati.genere);
	while(dati.genere!='m' && dati.genere!='f'){
		printf("NON VALIDO! Genere (m/f): ");
		scanf(" %c",&dati.genere);
	}
	printf("Altezza: ");
	scanf("%d",&dati.h);
	if(sel==1)
		_inserisci_testa(lista,dati);
	else if(sel==2)
		_inserisci_coda(lista,dati);
	else if(sel==3)
		_inserisci_posizione(lista,dati);
	else
		printf("Questo errore non sarebbe mai dovuto comparire. Ti sei scordato per caso qualcosa?");
}

void _inserisci_coda(tipolista *lista, tipopersona dati){
	tipoelemento *punt;
	if(_isEnd(*lista)){
		punt=malloc(sizeof(tipoelemento));
		punt->persona=dati;
		punt->next=NULL;
		*lista=punt;
	}
	else
		_inserisci_coda(&(*lista)->next,dati);
}

void _inserisci_testa(tipolista *lista, tipopersona dati){
	tipolista punt;
	punt=malloc(sizeof(tipoelemento));
	punt->persona=dati;
	punt->next=*lista;
	*lista=punt;
}

void _inserisci_posizione(tipolista *lista, tipopersona dati){
	tipoelemento *puntCorrente,*puntPrecedente;
	puntPrecedente=NULL;
	puntCorrente=*lista;
	int i=0,posizione;
	printf("Posizione a cui inserire: ");
	scanf("%d",&posizione);
	if(posizione<2){
		printf("Inserimento in testa");
		_inserisci_testa(lista,dati);
		return;
	}
	while(i<posizione-1){
		if(_isEnd(puntCorrente)){
			printf("Posizione non valida, inserimento in coda");
			_inserisci_coda(lista,dati);
			return;
		}
		else{
			puntPrecedente=puntCorrente;
			puntCorrente=puntCorrente->next;
		}
		i++;
	}
	_inserisci_testa(&puntCorrente,dati);
	puntPrecedente->next=puntCorrente;
}

void _elimina_testa(tipolista *lista){
	tipolista punt;
	punt=*lista;
	if(_isEnd(*lista)){
		printf("La lista è vuota!");
		return;
	}
	printf("VOCE RIMOSSA: ");
	_stampa(*lista);
	*lista=(*lista)->next;
	free(punt);
}

void _elimina_coda(tipolista *lista,tipolista puntPrecedente){
	if(_isEnd(*lista)){
		printf("La lista è vuota!");
		return;
	}
	if(_isEnd((*lista)->next)){
		if(_isEnd(puntPrecedente)){
			_elimina_testa(lista);
			return;
		}
		printf("VOCE RIMOSSA: ");
		_stampa(*lista);
		puntPrecedente->next=NULL;
		free(*lista);
		return;
	}
	_elimina_coda(&(*lista)->next,*lista);
}

void _elimina_posizione(tipolista *lista){
	tipoelemento *puntCorrente,*puntPrecedente;
	puntPrecedente=NULL;
	puntCorrente=*lista;
	int i=0,posizione;
	printf("Posizione da eliminare: ");
	scanf("%d",&posizione);
	if(posizione<1){
		printf("Posizione non valida");
		return;
	}
	if(posizione==1){
		_elimina_testa(lista);
		return;
	}
	while(i<posizione-1){
		if(_isEnd(puntCorrente)){
			printf("Posizione non valida");
			return;
		}
		puntPrecedente=puntCorrente;
		puntCorrente=puntCorrente->next;
		i++;
	}
	if(_isEnd(puntCorrente)){
		printf("Posizione non valida");
		return;
	}
	puntPrecedente->next=puntCorrente->next;
	free(puntCorrente);
}

int _media(tipolista lista){
	if(_isEnd(lista))
		return 0;
	else
		return lista->persona.h + _media(lista->next);
}

int _cont(tipolista lista){
	if(_isEnd(lista))
		return 0;
	else
		return 1+_cont(lista->next);
}

int _cont_f(tipolista lista){
	if(_isEnd(lista))
		return 0;
	else if(lista->persona.genere=='f')
		return 1+_cont_f(lista->next);
	else
		return 0+_cont_f(lista->next);
}

float _percentuale(tipolista lista){	//IO AMO LA RICORSIONE, LO AVRETE CAPITO, NON ROMPETE I COGLIONI!
	if(_cont(lista)>0)
		return 100*(float)_cont_f(lista)/_cont(lista);
	return -1;
}

void _cerca(tipolista lista){
	int i=1;
	str cercato;
	tipolista punt;
	punt=lista;
	printf("Nome da cercare: ");
	scanf("%s",cercato);
	while(_isEnd(punt)==false){
		if(strcmp(punt->persona.nome,cercato)==0){
			printf("%d. ",i);
			_stampa(punt);
		}
		punt=punt->next;
		i++;
	}
}
