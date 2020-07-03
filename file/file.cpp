#include <iostream> //library
#include <fstream>
#include <cstdlib> //library untuk clear screen

using namespace std;



int pilih, ketemu;
char yes;
string satu, dua;
char data[100]; 


int main() {
		
	awal:
	system("cls");
	cout << "Pilih salah satu menu dibawah :" << endl;
	cout << "	1. Buat File Teks" << endl;
	cout << "	2. Tambah Data File" << endl;
	cout << "	3. Tampilkan Data File" << endl;
	cout << "	4. Hapus File Teks" << endl;
	cout << "	5. Exit" << endl;
	cout << endl;
	cout << "Pilih Menu : "; cin >> pilih;

	if (pilih==1) {
		system("cls");
		cout << "\nMasukkan nama file : "; cin >> satu;
			ofstream outfile;
			outfile.open ("latihan.txt", ios::app);
			
			
			if(!outfile.fail())
       {
              //menulis ke dalam file
              outfile<<" "<<endl;
              outfile.close(); //menutup file
              cout<<"File latihan.txt telah dibuat"<<endl;
       }else{
              cout<<"File tidak ditemukan"<<endl;
       }
			 
		}
			
		
	else if (pilih==2) {
		system("cls");
		ofstream outfile;	
		
			cout << "Masukkan kata atau kalimat : "; cin >> data; cin.ignore();
				outfile << data << endl;
				outfile.close();
		
		cout << "Kata atau Kalimat " << data << " berhasil dimasukkan !!" <<endl;
	}
	else if (pilih==3) {
		system("cls");
		
			ifstream infile;
			infile.open("latihan.txt");
				cout << "File : " << endl << endl;
			infile >> data;
				cout << data << endl;
			infile.close(); 
   
		cout << "Kata atau Kalimat yang tertulis dalam file adalah  " << dua << endl;
	}
	else if (pilih==4) {
		 system("cls");
		cout << "Anda yakin ingin keluar? (y/n) : "; cin >> yes;
		
		
		
		
	}
	
	else if (pilih==5) {
		 system("cls");
		cout << "Anda yakin ingin keluar? (y/n) : "; cin >> yes;
		if (yes=='y' && yes=='Y') {
			return 0;
		}
		else if (yes=='n' && yes=='N') {
			goto awal;
		}
		
		else
			cout << "Salah";

		
		
		
	}

}
