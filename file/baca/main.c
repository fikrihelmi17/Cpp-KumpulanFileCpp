#include <stdio.h>


typedef struct{
	long nim;
	char nama[25];
	float ip;
} datamhs;

datamhs Msiswa;

FILE *Mhs;

int main() {
	Mhs = fopen("data.txt", "rb");

	
	while(!feof(Mhs)) {
		fread(&Msiswa, sizeof(Msiswa), 1, Mhs);
		printf("NIM : %ld\n",Msiswa.nim);
		printf("Nama : %s\n",Msiswa.nama);
		printf("IP : %f\n",Msiswa.ip);
		
	}
fclose(Mhs);
	return 0;
}
