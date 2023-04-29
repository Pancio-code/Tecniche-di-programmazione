#include<stdio.h>
int main(){
	int c1 = 0, c2 = 0, c4 = 0, c5= 0, c7 = 0, c8 = 0;
	int i = 0,k;
	int stra = 0;
	int n;
	int denied = 0;
	while(stra == 0){
		i++;
		for(k = 1; k < 7; k++){
			n = i*k;
			c1 = 0;
			c2 = 0;
			c4 = 0;
			c5 = 0;
			c7 = 0;
			c8 = 0;
			denied = 0;
			
			while(n > 0){
				switch(n % 10){
					case 0: denied = 1;
					case 1: c1 ++; break;
					case 2: c2 ++; break;
					case 3: denied = 1;
					case 4: c4 ++; break;
					case 5: c5 ++; break;
					case 6: denied = 1;
					case 7: c7 ++; break;
					case 8: c8 ++; break;
					case 9: denied = 1;
				}
				n = n/10;
			}
			if(denied == 1){
				break;
		    }
		    if(!(c1 == c2 == c4 == c5 == c7 == c8 == 1)){
		    	break;
			}
		}
		if(k == 7){
			stra = 1;
		}		
	}
	printf("Numero = %d\tper 2 = %d\tper 3 = %d\tper 4 = %d\tper 5 = %d\tper 6 = %d\n", i, i*2, i*3, i*4, i*5, i*6);
}


