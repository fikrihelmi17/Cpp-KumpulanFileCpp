/*Nama : Fikri Helmi Setiawan
  NPM : 0617104005 
*/

#include <stdio.h>
#include <stdlib.h>

struct clientData {
 int account; // account number
 char name[30]; // account name
double balance; // account balance
}inputD;

void outputdata(FILE *input);
int rekursif(int n);

int main(){
	int pilih,n;
	system("cls");
	printf("1. Rekursif\n");
	printf("2. Output Data\n");
	printf("Pilih : "); scanf("%d",&pilih);
	
	if (pilih==1) {
		system("cls");
		printf("Masukkan angka : "); scanf("%d",&n);
		printf("Hasil faktorial dari %d adalah : %d",n,rekursif(n));
		
	}
	
	else if (pilih==2) {	
		FILE *input;
		input = fopen("dataOutput.txt","r");
			if (input==NULL){
				printf("File Tidak Ada");
				}else{outputdata(input);
				}
				
			}
	else {
		main();
	}
	return 0;	
}
 
void outputdata(FILE *input){
	
	fscanf(input, "%d%29s%lf", &inputD.account, inputD.name, &inputD.balance );
	if(  inputD.account!=999 ) {
		printf( "\n%-10d%-13s%lf", inputD.account, inputD.name, inputD.balance );	
		outputdata(input);
	}else{
		fclose(input);
	}
}

int rekursif(int n) {
	
	if (n<=1) {
		return 1;
	}	
	else {
		return n*rekursif(n-1);
	}
}



