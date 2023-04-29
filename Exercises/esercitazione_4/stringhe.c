#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

char* copia(char s[], int N);

void seleziona_alcuni_char(char s[], int idxs[], int dim);

char* copia_con_eliminazione(char s1[], char s2[]);

char* inverti(char s[]);

void print_vocali(char s[]);

char* sostituisci_carattere(char s[], char c1, char c2);

bool minuscole_check(char s[]);

char* sostituisci_maiuscole(char s[]);

int main(void){

	int N = 7;
	int n = 5;
	char s[11] = "puntatore\0";
	 
	/********************************************************
    *              TEST copia                               *
    ********************************************************/
    	printf("Copio i primi %d valori della stringa s...\n", N);
    	char* char_copiato = copia(s, N);
    	printf("%s", char_copiato);
	printf("\n\n");

	/********************************************************
    *              TEST seleziona_alcuni_char               *
    ********************************************************/
	printf("Stampo i valori con indici idxs della stringa s...\n");
	int dims = 4;
	int idxs[dims] = {1, 3, 5, 11};
	seleziona_alcuni_char(s, idxs, dims);
 	printf("\n");
	
    /********************************************************
    *              TEST copia_con_eliminazione              *
    ********************************************************/
	printf("Elimino dalla stringa s tutti i char non presenti in s2...\n");
	char s2[5] = "ptr\0";
	char* char_eliminato = copia_con_eliminazione(s, s2);
	printf("%s", char_eliminato);
	printf("\n\n");

	/********************************************************
    *              TEST inverti                             *
    ********************************************************/
	printf("Inverto la stringa s...\n");
	char* char_invertito = inverti(s);
	printf("%s", char_invertito);
	printf("\n\n");

    /********************************************************
    *              TEST print_vocali                        *
    ********************************************************/
    	printf("Stampo le vocali contenute in s...\n");
	print_vocali(s);
	printf("\n\n");

    /********************************************************
    *              TEST sostituisci_carattere               *
    ********************************************************/
    	char c1 = 't';
	char c2 = 'm';
    	printf("stostituisco in s il carattere %c con il carattere %c le vocali contenute in s...\n", c1, c2);
	char* char_sostituito = sostituisci_carattere(s, c1, c2);
	printf("%s", char_sostituito);
	printf("\n\n");

	/********************************************************
    *              TEST minuscole_check              *
    ********************************************************/
    	printf("controllo che tutti i caratteri siano minuscoli...\n");
	printf( "%s\n", minuscole_check(s) ? "true: tutti i caratteri sono minuscoli" : "false: almeno un carattere è maiuscolo" );
	printf("\n\n");

	/********************************************************
    *              TEST sostituisci_maiuscole               *
    ********************************************************/
	printf("Sostituisco le lettere maiuscole nella stringa s3...\n");
	char s3[50] = "cHE bEllA e rIlAssANTe lEZIonE dI TDp\0";
	char *char_maiuscolo = sostituisci_maiuscole(s3);
	printf("%s", char_maiuscolo);
	printf("\n");

	free(char_copiato);
	free(char_eliminato);
	free(char_invertito);
	free(char_sostituito);	
	free(char_maiuscolo);
}

char* copia(char s[], int N) {
	char *copia=(char *)malloc(N*sizeof(char));
	for(int i=0 ; i < N ;i++ ) {
		copia[i]=s[i];
		if(s[i] == '\0') {
			break;
		}
	}
	if(copia[N-1] != '\0') {
		copia[N]='\0';	
	}
	return copia;
}

void seleziona_alcuni_char(char s[], int idxs[], int dim) {
	for(int i=0 ; i < dim;i++) {
		if( idxs[i] < strlen(s)) {
			printf("IL carattere in posizione %d e' %c\n",idxs[i],s[idxs[i]]);
		}
	}
	return;
}

char* copia_con_eliminazione(char s1[], char s2[]) {
	char* copia=(char *)malloc(strlen(s1)*sizeof(char));
	for(int i=0; i < strlen(s1);i++) {
		for(int k=0; k < strlen(s2);k++) {
			if( s1[i] != s2[k]) {
				copia[i]=' ';
			}
			else {
				copia[i]=s1[i];
				break;
			}
		}
		copia[strlen(s1)]='\0';
	}
	return copia;
}

char* inverti(char s[]) {
	char* inversa=(char *)malloc(strlen(s)*sizeof(char));
	for(int i=0; i < strlen(s);i++) {
		inversa[i]=s[strlen(s)-1-i];
	}
	inversa[strlen(s)]='\0';
	return inversa;
}

void print_vocali(char s[]) {
	for(int i=0; i < strlen(s); i++) {
		if(s[i] =='A' || s[i] =='a' || s[i] =='E' || s[i] =='e' || s[i] =='I' || s[i] =='i' || s[i] =='O' || s[i] =='o' || s[i] =='U' ||s[i] =='u') {
			printf("%c ",s[i]);
		}
	}
	return;
}
		
char* sostituisci_carattere(char s[], char c1, char c2) {
	char* nuova=(char *)malloc(strlen(s)*sizeof(char));
	for(int i=0; i < strlen(s); i++) {
		if( s[i]== c1 ) {
			nuova[i]=c2;
		}
		else {
			nuova[i]=s[i];
		}
	}
	nuova[strlen(s)]='\0';
	return nuova;
}

bool minuscole_check(char s[]) {
	for(int i=0; i < strlen(s) ;i++){
		if( s[i] < 'a' || s[i] > 'z') return false;
	}
	return true;
}				
				
char* sostituisci_maiuscole(char s[]) {
	char* msl=(char *)malloc(strlen(s)*sizeof(char));
	for(int i =0; i < strlen(s) ;i++) {
		if( i == 0 || s[i-1] == ' ' ) {
			if( s[i] >= 'a' && s[i] <= 'z' )
				msl[i] = s[i] - 'a' +'A';
			else
				msl[i] = s[i];
		}
		else {
			if( s[i] >= 'A' && s[i] <= 'Z' )
				msl[i] = s[i] - 'A' +'a';
			else
				msl[i] = s[i];
		}	
	}
	msl[strlen(s)]='\0';
	return msl;
}
			
						
