#include <stdlib.h>
#include <stdio.h>
#include<string.h>
#include "functions.h"

bool tuttiMinuscoli(char *s){
	if( s[0]=='\0' ) return true;
	else return (s[0] >= 'a' && s[0] <= 'z') && tuttiMinuscoli(s+1);
}

void converti(char *s){
	if( s[0]=='\0' ) return;
	else {
		if(s[0] >= 'a' && s[0] <= 'z') {
			s[0]-=32;
		}
		converti(s+1);
	}
}

int contaParentesi(char *s){
	if( s[0]=='\0' ) return 0;
	else if(s[0] == '(' || s[0] == ')' || s[0] == '[' || s[0] == ']' || s[0] == '{' || s[0] == '}' )
		return 1 + contaParentesi(s+1);
	else 
		return contaParentesi(s+1);
}

void concatenate(char* dest, char* src){
	int l=strlen(dest);
	if( src[0]=='\0' ) {
		return;
	}
	else {
		dest[l]=src[0];
		dest[l+1]='\0';
		concatenate(dest,src+1);
	}
}

float prodotto(float a[], int n){
	if(n==0) return 1;
	else return a[0] * prodotto(a+1, n-1);
}


int aux_lunghezza(TipoSCL head_ptr) {
	if(head_ptr==NULL) return 0;
	else return 1 + aux_lunghezza(head_ptr->next);
}
float aux_somma(TipoSCL head_ptr) {
	if(head_ptr==NULL) return 0;
	else return head_ptr->info + aux_somma(head_ptr->next);
}

float SCL_media(TipoSCL head_ptr){
	int l=aux_lunghezza(head_ptr);
	float s=aux_somma(head_ptr);
	return s/l;
}

void somma_SLC(TipoSCL head_ptr,int n, int i,float sum_till_now){
	if( n==0 ) return;
	else {
		if( i > 0) {
			head_ptr->info=sum_till_now + head_ptr->info;
		}
		somma_SLC(head_ptr->next, n-1,i+1, head_ptr->info);
	}
	return;
}
		
void SCL_integral(TipoSCL head_ptr){
	if(head_ptr==NULL) return;
	somma_SLC(head_ptr, aux_lunghezza(head_ptr),0, 0.0f);
	return;		
}

float SCL_dot(TipoSCL head1_ptr, TipoSCL head2_ptr) {
	if(head1_ptr==NULL) return 0;
	else return (head1_ptr->info * head2_ptr->info) + SCL_dot(head1_ptr->next,head2_ptr->next);
  
  return -1;
}



