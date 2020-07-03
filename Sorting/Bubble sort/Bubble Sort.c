#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int A[10]={5,10,11,2,8,13,7,20,35,18};
int i;
int swap;

void tukar(int *a, int *b);

main() {
	
do {
	swap=0;
	for(i=0; i<10; i++) {
		if (A[i] > A[i+1]) {
			tukar (&A[i], &A[i+1]); 
			swap=1;
		}
	} 
} while(swap==1);
for(i=1;i<=10;i++) {
	printf("%d \n",A[i]);
}
return 0;
}

void tukar(int *a, int *b) {
	int c;
	c=*a;
	*a=*b;
	*b=c;
}

