#include <stdio.h>
#include <conio.h>

int n;

void kalender();
void pencarian();
void pengurutan(int n);

int main() {
	int pilih;
	system("cls");
	printf("============== Program Ajaib ==============\n\n");
	printf("Apa yang ingin anda lakukan?\n");
	printf("1. Kalender\n");
	printf("2. Pencarian\n");
	printf("3. Pengurutan\n");
	printf("Pilih : "); scanf("%d",&pilih);
	
	switch(pilih) {
		case 1 : kalender(); break;
		case 2 : pencarian(); break;
		case 3 : pengurutan(n); break;
		default : 
			printf("\nMasukkan hanya dari 1 - 3 !!!\n");
			system("pause");
		main();	
	}

	return 0;
}

void kalender() {
	int n;
	char y;
	system("cls");
	printf("============== Program Ajaib ==============\n\n");
	printf("Program ini membaca sebuah bilangan bulat antara 1 - 12 kemudian akan menampilkan nama bulan berdasarkan inputan anda.\n\n");
	printf("Masukkan angka dari 1 - 12 : "); scanf("%d",&n);
	
	switch(n) {
		case 1 : 
		printf("\nBerdasarkan inputan anda, nama bulan yang keluar adalah Januari\n\n"); 
		system("pause");
		main();
		break;
		case 2 : printf("\nBerdasarkan inputan anda, nama bulan yang keluar adalah Februari\n\n"); 
		system("pause");
		main();
		break;
		case 3 : printf("\nBerdasarkan inputan anda, nama bulan yang keluar adalah Maret\n\n"); 
		system("pause");
		main();
		break;
		case 4 : printf("\nBerdasarkan inputan anda, nama bulan yang keluar adalah April\n\n");
		system("pause");
		main();
		break;
		case 5 : printf("\nBerdasarkan inputan anda, nama bulan yang keluar adalah Mei\n\n"); 
		system("pause");
		main();
		break;
		case 6 : printf("\nBerdasarkan inputan anda, nama bulan yang keluar adalah Juni\n\n"); 
		system("pause");
		main();
		break;
		case 7 : printf("\nBerdasarkan inputan anda, nama bulan yang keluar adalah Juli\n\n"); 
		system("pause");
		main();
		break;
		case 8 : printf("\nBerdasarkan inputan anda, nama bulan yang keluar adalah Agustus\n\n"); 
		system("pause");
		main();
		break;
		case 9 : printf("\nBerdasarkan inputan anda, nama bulan yang keluar adalah September\n\n"); 
		system("pause");
		main();
		break;
		case 10 : printf("\nBerdasarkan inputan anda, nama bulan yang keluar adalah Oktober\n\n"); 
		system("pause");
		main();
		break;
		case 11 : printf("\nBerdasarkan inputan anda, nama bulan yang keluar adalah November\n\n"); 
		system("pause");
		main();
		break;
		case 12 : printf("\nBerdasarkan inputan anda, nama bulan yang keluar adalah Desember\n\n"); 
		system("pause");
		main();
		break;
		default : 
		system("cls");
		printf("Data yang anda masukkan haruslah dari 1 - 12\n\n");
		system("pause");
		kalender();			
			
	}
}


void pencarian() {
	int i,d,t;
	int n;
	n=8;
	int j;
	int k;
	int x;
	int found;
	system("cls");
	printf("============== Program Ajaib ==============\n\n");
	int A[8]={5,3,2,1,3,2,4,5}; //data acak
	
	printf("Nilai dalam array : ");
	for(i=0;i<=n-1;i++){
		printf("%d ",A[i]);
	}
	
	printf("\n\n");
	system("pause");
	printf("\n\n");	
	
	//dari sini diurutkan dulu menggunakan insertion sort
		for (i=1;i<=n-1;i++) {
            d=i;

		while ( d > 0 && A[d] < A[d-1]) {
            t = A[d];
            A[d] = A[d-1];
            A[d-1] =t;
		d--;
		}
	}
	//sampe sini
	
	printf("Data terurut menjadi : ");
	
	for(i=0;i<=n-1;i++) {
        printf("%d ", A[i]);
	}
	printf("\n\n");
	
	
	//barulah kita cari
	printf("\nMasukkan nilai yang akan dicari : "); scanf("%d",&x);
	i=0;
	j=7;
	found=0;
		while((found == 0) && (i<=j)){
			k=(i+j)/2;
			if(A[k] == x){
				found=1;
			}else{
				if(A[k] < x){
					i=k+1;
				} else{
					j=k-1;
				}
			}
		}
	
	if(found == 1){
		printf("\nDitemukan di elemen ke- %d ",k);	
	} else{
		printf("\nTidak ditemukan");
	}
	
	printf("\n\n");
	system("pause");
	main();
}


void pengurutan(int n) {
	int d,i,t;
	int array[100];
	system("cls");
	printf("============== Program Ajaib ==============\n\n");
	printf("Masukkan jumlah nilai yang akan diinput ke array : "); scanf("%d",&n);
	for (i=0;i<n;i++) {
		printf("\nMasukkan nilai ke elemen %d : ",i);
		scanf("%d",&array[i]);
	}
	printf("\nData yang dimasukkan : ");
	for (i=0;i<n;i++) {
		printf("%d ",array[i]);
	}
	printf("\n");
	system("pause");
	printf("\n");
	
	for (i=1;i<=n-1;i++) {
            d=i;

		while ( d > 0 && array[d] < array[d-1]) {
            t = array[d];
            array[d] = array[d-1];
            array[d-1] =t;
		d--;
		}
	}

	printf("Data terurut menjadi :\n");

	for(i=0;i<=n-1;i++) {
        printf("%d\n", array[i]);
	}
	system("pause");
	main();
}
