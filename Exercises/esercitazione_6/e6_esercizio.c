#include "e6_esercizio.h"


int lunghezza(char *s){
	if(*s == '\0')  return 0;
	else  return 1+lunghezza(s+1);
}

int char_in_posizione(char *s, char ch){
	static int i = 0;
	if( s[i]=='\0' ) return -1;
	else if( s[i]==ch ) return i;
	i++;
	char_in_posizione(s,ch);
}

void vec_integral(float* v, int n){
	static int i = 0;
	static float sum_till_now= 0.0f;
	if( n==0 ) return;
	else {
		sum_till_now+=v[i];
		v[i]=sum_till_now;
		i++;	
		vec_integral(v,n-1);
	}
	return;	
}

/*int char_in_posizione(char *s, char ch){
	return char_in_posizione_aux(s,ch,lunghezza(s));
}

int char_in_posizione_aux(char* s, char ch, int i) {
	if( *s== '\0')  return -(i+1);
	else if( *s==ch )  return 0;
	return 1 + char_in_posizione_aux(s+1,ch,i);
}


void vec_integral(float* v, int n){
	vec_integral_aux(v, n, 0, 0.0f);
	return;	
}

void vec_integral_aux(float* v, int n, int i, float sum_till_now) {
	if( n==0 ) return;
	else {
		if( i > 0) {
			v[i]=sum_till_now + v[i];
		}
		vec_integral_aux(v, n-1, i+1, v[i]);
	}
	return;	
}

*/
float vec_dot(float* v1, float* v2, int n) {
	if( n==0 ) return 0;
	else return (v1[0]*v2[0]) + vec_dot(v1+1,v2+1,n-1);
}
