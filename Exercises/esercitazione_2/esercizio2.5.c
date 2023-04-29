#include<stdio.h>

int main() {
	char nome[20];
	int totale = 0,i=0,ndd;
	printf("Numero del destino\n");
	printf("Inserisci il tuo nome( . per finire):\n");
	scanf("%s",nome);
	while( nome[i] != '.' ) {
		totale = totale + nome[i];
		i++;	
	}
	if( totale == 11 || totale == 22 || totale <= 9 ) {
		ndd=totale;
	}
	while(totale != 11 && totale != 22 && totale > 9 ) {
		ndd = 0;
		while( totale > 0) {
			ndd += totale % 10;
			totale = totale / 10;
		}
		totale=ndd;
	}
	printf("Il numero del destino e' %d\n", ndd);
	if(ndd==1)
		printf("Dotato di spirito di iniziativa, intraprendente, capace di comandare, indipendente, determinato, individualista.\n");
	if(ndd==2)
		printf("Collaborativo, versatile, rispettoso, capace lavorare in team, buon mediatore.\n");
	if(ndd==3)
		printf("Auto-espressione, comunicatività, socializzazione, vena artistica, entusiasmo verso la vita.\n");
	if(ndd==4)
		printf("Valori forti, ordine dedizione, ribellione, in costante evoluzione.\n");
	if(ndd==5)
		printf("Espansivo, visionario, avventuroso, uso costruttivo della libertà.\n");
	if(ndd==6)
		printf("Responsabile, protettivo, premuroso, di supporto, disponibile verso la comunità, equilibrato, compassionevole.\n");
	if(ndd==7)
		printf("Spirito analitico, comprensivo, preparato, consapevole, studioso, riflessivo.\n");
	if(ndd==8)
		printf("Ambizioso, che punta al prestigio e al potere, materialista.\n");
	if(ndd==9)
		printf("Filantropo, generoso, altruista, creativo, forte senso del dovere.\n");
	if(ndd==11)
		printf("Spirituale, intuitivo, ascetico, idealitsa, sognatore.\n");
	if(ndd==22)
		printf("MASTER BUILDER: temerario, forte, abile nel comandare.\n");


}
		
			
			
	
