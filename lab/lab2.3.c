#include <stdio.h>
#define LEN_MAX 50
#define EL_MAX 10
typedef char str[LEN_MAX];
typedef struct FILM {
	str titolo;
	struct DATA {
		int giorno;
		int mese;
		int anno;
		} data;
	str regista;
	str attore;
	int short giudizio;
	} film;
int tot_film=0;

film _inserisci(){
	film temp;
	printf("Titolo film: ");
	scanf("%s",temp.titolo);
	printf("Data film: ");
	scanf("%d",&temp.data.giorno);
	scanf("%d",&temp.data.mese);
	scanf("%d",&temp.data.anno);
	printf("Regista: ");
	scanf("%s",temp.regista);
	printf("Attore principale: ");
	scanf("%s",temp.attore);
	printf("Valutazione da 0 a 5: ");
	scanf("%d",&temp.giudizio);
	while(temp.giudizio<0||temp.giudizio>5){
		printf("Valutazione non accettabile, riprova!\n");
		printf("Valutazione da 0 a 5: ");
		scanf("%d",&temp.giudizio);
	}
	tot_film++;
	return temp;
}

void _stampa(film raccolta[EL_MAX],int i){
	printf("\nFilm numero %d:\n",i+1);
	printf("Titolo: %s\n",raccolta[i].titolo);
	printf("Data: %d/%d/%d\n",raccolta[i].data.giorno,raccolta[i].data.mese,raccolta[i].data.anno);
	printf("Regista: %s\n",raccolta[i].regista);
	printf("Attore principale: %s\n",raccolta[i].attore);
	printf("Giudizio: %d",raccolta[i].giudizio);
}

float _media(film raccolta[EL_MAX]){
	int i,somma=0;
	for(i=0;i<tot_film;i++)
		somma+=raccolta[i].giudizio;
	return somma/tot_film;
}

void _cerca_titolo(film raccolta[EL_MAX]){
	int i,j,k=0,trovato=0;
	str cerca;
	scanf("%c",&cerca[0]);
	printf("Che titolo vuoi cercare? ");
	for(j=0;cerca[j-1]!='\n';j++){
		scanf("%c",&cerca[j]);
	}
	k=j-2;
	for(i=0;i<tot_film;i++){
		for(j=0;j<k;j++)
			if(raccolta[i].titolo[j]!=cerca[j]){
				trovato=0;
				break;
			}
			else
				trovato=1;
		if(trovato==1)
			_stampa(raccolta,i);
	}
	if(trovato==0)
		printf("\nElemento non trovato\n");
}

void _cerca_giudizio(film raccolta[EL_MAX]){
	int i,cerca,trovato=0;
	printf("Che valutazione vuoi cercare? ");
	scanf("%d",&cerca);
	while(cerca<0||cerca>5){
		printf("Valore non valido, riprova!\n");
		printf("Che valutazione vuoi cercare? ");
		scanf("%d",&cerca);	
	}
	for(i=0;i<tot_film;i++)
		if(raccolta[i].giudizio==cerca){
			_stampa(raccolta,i);
			trovato=1;
		}
	if(trovato==0)
		printf("\nElemento non trovato\n");
}

int main(){
	int sel,i;
	film raccolta[EL_MAX];
	while(0<1){
		printf("\nMENU\n");
		printf("1. Inserisci film\n");
		printf("2. Stampa film\n");
		printf("3. Stampa valutazione media\n");
		printf("4. Verifica titolo\n");
		printf("5. Verifica valutazione\n");
		printf("\n0. Esci\n");
		printf("Selezione: ");
		scanf("%d",&sel);
		switch(sel){
			case 0:
				return 0;
				break;
			case 1:
				if(tot_film<EL_MAX)
					raccolta[tot_film]=_inserisci();
				else
					printf("Numero massimo di film raggiunto!\n");
				break;
			case 2:
				for(i=0;i<tot_film;i++)
					_stampa(raccolta,i);
				printf("\nHai ancora %d posti per altri film!\n\n",EL_MAX-tot_film);
				break;
			case 3:
				printf("Media giudizi: %.1f",_media(raccolta));
				break;
			case 4:
				_cerca_titolo(raccolta);
				break;
			case 5:
				_cerca_giudizio(raccolta);
				break;
			default:
				printf("Selezione non valida\n");
				break;
		}	
	}
}