#include <stdio.h>


typedef struct{
	long nim;
	char nama[25];
	float ip;
} datamhs;

datamhs Msiswa;

FILE *Mhs;

int main() {
	Mhs = fopen("data.txt", "wb");
	printf("\nNIM : ");
	scanf("%ld", &Msiswa.nim);
	
	while(Msiswa.nim!=9999) {
		printf("\nNama : ");
		scanf("%s", Msiswa.nama);
		printf("\nIP : ");
		scanf("%f",&Msiswa.ip);
		
		fwrite(&Msiswa, sizeof(Msiswa),1,Mhs);
		printf("\nNIM : ");
		scanf("&ld", &Msiswa.nim);
	}
fclose(Mhs);
	return 0;
}
