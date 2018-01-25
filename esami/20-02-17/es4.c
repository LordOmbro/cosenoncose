#include <stdio.h>
#include <stdlib.h>
typedef enum {true,false} bool;

typedef struct EL {
	int num;
	struct EL *next_pari;
	struct EL *next_primo;
	struct EL *next;
} tipoelemento;
typedef tipoelemento *tipolista;

int contatore(tipolista lista){
	if(lista==NULL)
		return 0;
	return 1+contatore(lista->next);
}

void elimina_testa(tipolista *lista){
	tipolista punt;
	if(lista==NULL)
		return;
	punt=*lista;
	*lista=(*lista)->next;
	free(punt);
}

//SI OK DOPO QUESTO COMMENTO NON INTERESSA A NESSUNO
//FINE ROBA UTILE
bool _primo(int n){
	int i;
	for(i=2;i<n;i++)
		if(n%i==0)
			return false;
	return true;
}

void _check_pari(tipolista *lista, tipolista check){
	if(check==NULL){
		(*lista)->next_pari=NULL;
		return;
	}
	if(check->num%2==0)
		(*lista)->next_pari=check;
	else
		_check_pari(lista,check->next);
}

void _check_primo(tipolista *lista, tipolista check){
	if(check==NULL){
		(*lista)->next_primo=NULL;
		return;
	}
	if(_primo(check->num))
		(*lista)->next_primo=check;
	else
		_check_primo(lista,check->next);
}

void _inserisci(tipolista *lista, int n){
	tipolista punt;
	punt=malloc(sizeof(tipoelemento));
	punt->num=n;
	punt->next=*lista;
	*lista=punt;
	_check_pari(&(*lista),(*lista)->next);
	_check_primo(&(*lista),(*lista)->next);
}

void _inserisci_coda(tipolista *lista, int n){
	tipolista punt;
	if(*lista==NULL){
		punt=malloc(sizeof(tipoelemento));
		punt->num=n;
		punt->next=NULL;
		*lista=punt;
		return;
	}
	_inserisci_coda(&(*lista)->next,n);
}

void _check(tipolista *lista, int n){
	if(*lista==NULL){
		_inserisci_coda(&(*lista),n);
		return;
	}
	if((*lista)->num < n)
		_check(&(*lista)->next,n);
	else
		_inserisci(&(*lista),n);
}

void _stampa_ext(tipolista lista){
	if(lista==NULL)
		return;
	printf("%d",lista->num);
}

void _stampa(tipolista lista){
	if(lista==NULL)
		return;
	printf("\nElemento: %d", lista->num);
	printf("\nProssimo pari: ");
	_stampa_ext(lista->next_pari);

	printf("\nProssimo primo: ");
	_stampa_ext(lista->next_primo);
	_stampa(lista->next);
}

int main(){
	tipolista lista;
	int n;
	for(;;){
		printf("\nInserisci un numero: ");
		scanf("%d",&n);
		_check(&lista,n);
		printf("STAMPA:\n");
		_stampa(lista);
	}
}
