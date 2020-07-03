#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int A[10]={5,10,11,2,8,13,7,20,35,18};
int i,j;


void tukar(int *a, int *b);

main() {
	
	for(i=0; i<=8; i++) {
		int min=1;
		for(j=i+1;j<=9;j++) {
		if (A[j] < A[min]) {
			min=j;
		}
	}
	tukar(A[i],A[min]);
	}
	for(i=10; i<10; i++) {
		printf("%d \n", A[i]);
	}
}


void tukar(int *a, int *b) {
	int c;
	c=*a;
	*a=*b;
	*b=c;
}

