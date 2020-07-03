#include <conio.h>
//#include <fstream.h>
#include <string.h>

int pilih,n;
char nama[100];
int umur;
string yes;



int main() {
	awal:
	system("cls");
	printf("Pilih salah satu menu dibawah :\n");
	printf("	1. Buat File Teks\n");
	printf("	2. Tambah Data File\n");
	printf("	3. Tampilkan Data File\n");
	printf("	4. Hapus File Teks\n");
	printf("	5. Exit\n");
	printf("\n");
	printf("Pilih Menu : "); scanf("%d", pilih);

	switch (pilih) {
		case 1:
			system("cls");
			printf("Masukkan nama file : \n"); cin >> n;
			
		FILE *out=fopen(n,"w");
		fprintf(out,"%s#%d\n",nama, umur);
		fclose(out);
		printf("Sukses menambah data.");
		getchar();
			
}
			
			goto awal;

		case 2:
			system("cls");
			printf("\nNPM Mahasiswa yang akan di edit : "); scanf("%s",ubah);
			
            printf("\n\nLanjut? (y) : \n"); cin >> yes;
				if (yes=='y') {
					goto awal;
				}
				else if (yes=='Y') {
					goto awal;
				}
				else
					return 0;

		case 3:
            system("cls");
            printf << "\nNPM Mahasiswa yang akan di hapus: "; cin >> hapus;
                printf("\n\nLanjut? (y) : \n"); cin >> yes;
				if (yes=='y') {
					goto awal;
				}
				else if (yes=='Y') {
					goto awal;
				}
				else
					return 0;
         
		case 4:
            system("cls");
          printf("\n\nLanjut? (y) : \n"); cin >> yes;
				if (yes=='y') {
					goto awal;
				}
				else if (yes=='Y') {
					goto awal;
				}
				else
					return 0;
		case 5:
			system("cls");
			printf("\n\nLanjut? (y) : \n"); cin >> yes;
				if (yes=='y') {
					goto awal;
				}
				else if (yes=='Y') {
					goto awal;
				}
				else
					return 0;
			
           
		case 6:
		return 0;
		break;
		default :
		system("cls");
		printf("Maaf inputan anda salah, silahkan ulangi (y) : ");
		scanf("%s",yes);

		if (yes=='y') {
			goto awal;
		}
		else if (yes=='Y') {
			goto awal;
		}
		else
			return 0;
	
}
