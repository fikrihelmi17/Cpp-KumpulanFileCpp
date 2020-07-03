//#include <windows.h> 
#include <cstdlib>// untuk mengahpus screen
#include <iostream> //input output
#include <string>
#include <stdio.h>

#include <stdlib.h>
#include <string.h>
#include <fstream> //file
#define nMax 30

using namespace std;

typedef struct{
int TI[nMax+1];
int nEff;
}TabInt;

void exit();

void listatm(string);
void mpin(string);
void terbilang(long x);//jang di tuliskeun
void mainmenu();

// Definisi prototype
void getMenuPilihTransfer();
void cetakTabel(TabInt T);
void addElmTab(TabInt *T, int x);
void urutBubbleDesc(TabInt *T);
void urutBubbleAsc(TabInt *T);
void terbilang(long x);



int choice,menuatm, confirmation, bayar, kembali;
bool cinfail;
string username, password, password2;
int yes;
char lajutya;

char y1, y2, y3, y4, y5, y6, y7, y8;
int i=0, j=0;
int pin;
int npin;
int fpin=1;   //pin sementara
int sal=7101000;//saldo sementara
int N, TR, TF;
int T=0;
TabInt Tab1,Tab2;


class User {
	public:
    string username;
    string password;

		void userRegister() {
			ofstream usersFile ("userData.txt");
			if (!usersFile.is_open()) {
				usersFile.open("userData.txt");
			}

            usersFile << username << " " << password << endl;
            usersFile.close();
		}
	};


void login() {
		//metode login
        string inputUsername; //masuk ke login
        string inputPassword;

        //system("clear");
        cout << "\n\n\n";
        cout << "================== LOGIN =======================\n";
        cout << "Silahkan Masukkan Username dan Password Anda\n";
        cout << "Username : "; cin >> inputUsername;
        cout << "Password : "; cin >> inputPassword;
        cout << "\n\n\n";

        string userAndPass = inputUsername + " " + inputPassword; //tah didieu ngahijikeun username jeung paswword

        int offset;
        string line;
        ifstream usersFile;
        usersFile.open ("userData.txt");

			if(usersFile.is_open()) {
				bool found = false;//lamun salah moal kabaca
					if(usersFile.is_open()) {
						while(getline(usersFile,line) && !found) {
							if (line.compare(userAndPass) == 0) {
								found = true;
                         }
                    }
       usersFile.close();

           if(found) {

            mpin(inputUsername);

            }
                else {
                    //cout << "\n "<< inputUsername << " , Username dan Password yang anda masukkan tidak sesuai";
                    cout << "\n (!!!)Username dan Password yang anda masukkan tidak sesuai";
                    login();
                }
            }

			usersFile.close();
        }
        else
            cout << "Unable to open userData.txt file." << endl;
    };

void mpin(string inputUsername){
    int i=0;
    logpin: // Perintah login pin akan dipanggil oleh syntax "goto"
        system("clear");
        cout<<"********** Masukkan PIN **********\n";
        cout<<"MASUKAN PIN ANDA:\n"; cin >>pin;
        if (pin==fpin) {
        //goto menuatm;
        listatm(inputUsername);
        }
        else if (i<2) {// diberi kesempatan memasukan PIN sebanyak 3x.
            cout<<"PIN YANG ANDA MASUKAN SALAH!\n tekan[ENTER]";
            i=i+1;
            getch();
            goto logpin;

        } else {
        cout<<"Anda telah 3x salah memasukan PIN.\n";
        cout<<"Mohon maaf, account anda telah kami blokir.\n";
        cout<<"Silahkan hubungi Customer Service kami.\n";
        exit();
        }
}

void registerme(){
    User user1;
    system("clear");
    cout << "Selamat Datang! Register \n-------------------------------\n\nSilahkan Daftarkan Diri Anda.\nMasukkan Username Baru   : ";
    cin >> user1.username;

    cout << "Masukkan Password Baru   : ";
    cin >> user1.password;

    user1.userRegister();
    cout << "Selamat Akun Anda Telah Terdaftar\n";
}


void exit(){
    exit(0);
}

void cek_saldo(){//cek saldo
    exit(0);
}

void listatm(string inputUsername){//menu atm
MenuAtmAwal :
system("clear");
 cout << "\n\n\n                Menu ATM\n-----------------------------------------------\n\n Pengguna : ("<< inputUsername << ")\n\n";//can di globalkeun  @@@
				
				cout << "\n\n\n";
                cout << "1. Cek Saldo\n";
                cout << "2. Penarikan\n";
                cout << "3. Transfer\n";
                cout << "4. Bayar/Beli\n";
                cout << "5. Menyimpan Uang\n\n";

                cout << "Pilih Menu : "; cin >> menuatm;

				switch (menuatm) {
					case 1 :    // Pengecekan Saldo
                                cout<<"*************** CEK SALDO ***************\n";
                                cout<<"Saldo Anda Saat ini:Rp. "<<sal<<" \n";
                                cout<<"Terbilang: "; terbilang(sal);cout<<" Rupiah\n";
                                cout<<"[0] Kembali ke menu";
                              getch();
                                goto MenuAtmAwal;
                                break;
					case 2 :
						//Penarikan Saldo";
						do {
                            jmltarik:
                            system("clear");
                            cout<<"*************** TARIK TUNAI ***************\n";
                            cout<<"Masukan Jumlah yang akan ditarik:"; cin>>TR;
                            system("clear");
                            cout<<"*************** TARIK TUNAI ***************\n";
                            cout<<"Jumlah Penarikan:Rp. "<<TR<<"\n";
                            cout<<"Terbilang: "; terbilang(TR); cout<<"Rupiah\n";
                            cout<<"Apakah anda ingin melakukan transaksi ini?(y/t):";cin>>y6;
                            if (y6=='y' || y6=='Y') {
                            goto tarik;
                            }
                            else {
                            goto MenuAtmAwal;
                            }
                            tarik://penarikan uang
                                    if (TR < 10000) {
                                    cout<<"Nominal harus kelipatan Rp.10000,- !";
                                   getch();
                                    goto jmltarik;
                                    } else if (sal < TR) {
                                    cout<<"Saldo anda tidak mencukupi. Saldo anda saat ini:Rp.  "<<sal<<"\n";
                                    }else if (sal >= TR) {
                                    sal = sal - TR;
                                    cout<<"Transaksi berhasil. Saldo anda sekarang: Rp.  "<<sal<<"\n";
                                    addElmTab(&Tab2,TR);//@@@PerbaikanData@@@//
                                    }
                            cout<<"Ingin melakukan transaksi lagi ?(y/t):"; cin>> y7;
                            }
                        while(y7=='y' || y7=='Y');

                        goto MenuAtmAwal;
                        break;
					case 3 :
						//Transfer
						do {
                                pilihtransfer:
                                system("clear"); // Membersihkan layar
                                getMenuPilihTransfer(); // Memanggil prosedur Menu Pilih Transfer
                                cout<<"Masukan Pilihan:"; cin>>y2;
                                system("clear");
                                    switch(y2) {
                                        case '1': { // Transfer dana ke rekening Bank ABC
                                        cout<<"*************** KE REKENING BANK Syariah ***************\n";
                                        cout<<"Masukan No.Rek Tujuan:";cin>>T;
                                        system("clear");
                                        cout<<"*************** KE REKENING BANK Syariah ***************\n";
                                        cout<<"Masukan Nominal yang akan ditransfer:"; cin>>N;
                                        system("clear");
                                        cout<<"*************** KE REKENING BANK Syariah ***************\n";
                                        cout<<"Rekening Tujuan:%d\n"<<T;
                                        cout<<"Jumlah Transfer:%d\n"<<N;
                                        cout<<"Terbilang:"; terbilang(N); cout<<"Rupiah\n";
                                        cout<<"Apakah anda ingin melakukan transaksi ini?(y/t):";cin>>y3;
                                        if (y3=='y' || y3=='Y') {
                                        goto transferabc;
                                        }
                                        else {
                                        goto MenuAtmAwal;
                                        }
                                        transferabc:
                                                if (sal < N) {
                                                cout<<"Saldo anda tidak mencukupi. Saldo anda saat ini:Rp. "<<sal<<"\n";
                                                }
                                                else if (sal>=N) {
                                                sal = sal - N;
                                                cout<<"Transaksi berhasil. Saldo anda sekarang:Rp. "<<sal<<"\n";
                                                addElmTab(&Tab1, N);
                                                }
                                                break;
                                                }
                                        case '2': { // Transfer dana ke rekening bank lain
                                        cout<<"*************** KE REKENING BANK LAIN ***************\n";
                                        cout<<"Masukan No.Rek Tujuan:"; cin>>T;
                                        system("clear");
                                        cout<<"*************** KE REKENING BANK LAIN ***************\n";
                                        cout<<"Masukan Nominal yang akan ditransfer:";cin>>N;
                                        system("clear");
                                        cout<<"*************** KE REKENING BANK LAIN ***************\n";
                                        cout<<"Rekening Tujuan:     "<<T<<"\n";
                                        cout<<"Jumlah Transfer:Rp.  "<<N<<"\n";
                                        cout<<"Terbilang: "; terbilang(N); cout<<"Rupiah\n";
                                        cout<<"Biaya Transfer ke rekening bank lain: Rp.7500,-\n";
                                        cout<<"Apakah anda ingin melakukan transaksi ini?(y/t):";cin>>y4;
                                        if (y4=='y' || y4=='Y'){
                                        goto transferlain;
                                        }
                                        else {
                                        goto MenuAtmAwal;
                                        }
                                        transferlain:
                                        TF=7500; // Biaya transfer ke rekening bank lain
                                            if (sal < N) {
                                            cout<<"Saldo anda tidak mencukupi. Saldo anda saat ini:Rp. "<<sal<<"\n";
                                            }
                                            else if (sal>=N) {
                                            sal = sal - N - TF;
                                            cout<<"Transaksi berhasil. Saldo anda sekarang:Rp.  \n"<<sal<<"\n";
                                            addElmTab(&Tab1, N);
                                            addElmTab(&Tab1, TF);
                                            }
                                            break;
                                            }
                                        case '3': { // Kembali ke menu utama
                                        goto MenuAtmAwal;
                                        break;
                                        }
                                        default : { // Memasukan input selain angka 1-3
                                        getMenuPilihTransfer();
                                        cout<<"Input Salah(Masukan angka 1-3)";
                                     getch();
                                        goto pilihtransfer;
                                        break;
                                        }
                                    }
                                cout<<"Ingin transfer lagi? (y/t):"; cin>>y5;
                                system("cls");
                                }
                                while (y5=='y' || y5=='Y');
                                goto MenuAtmAwal;
                                break;


					case 4 ://ini belum bayar / beli : rek air,rek listrik, pulsa
						system("clear");
						cout << "Bayar/Beli\n-------------------------------\n";
						cout << "1. Rek Air\n2. Rek Listrik\n3. Pulsa\n\n";
						cout << "Pilih Menu : "; cin >> bayar;

					case 5 ://ini belum menyimpan uang
						system("clear");
						cout << "Menyimpang Uang";
					default :
                            lepatwae:
						//system("clear");
						cout << "\n Inputan yang anda masukkan salah\n\n";
						cout << "[0] kembali ke Menu Atm: "; cin >> yes;
						if (yes==0) {
                            goto MenuAtmAwal;
                        }
                        else if (yes!=0) {
                            goto lepatwae;
                        }




            }




}

void mainmenu(){
    pertamamulai:
     cout << "Hai, Anda ingin login atau mendaftar?\n\n";
     cout << "[1] Login\n";
     cout << "[2] Daftar\n";
     cout << "[3] Keluar" <<endl;
     cout << "\nPilih Menu : "; cin >> choice;

     /*do{
		cinfail = cin.fail();
		cin.clear();
		cin.ignore(10000,'\n');
		system("clear");
	}while(cinfail == true);{
	*/
        switch(choice){
            case 1:
                system("clear");
                login();
                break;

            case 2:
                registerme();
				system("clear");
				mainmenu();
                break;

            case 3:
                exit();
            default :
                system("clear");
                cout << "Maaf, inputan yang anda masukkan salah, silahkan ulangi (y/Y) : ";//inputtan tidak sesuai
                cin >> lajutya;
                if (lajutya=='y') {
                    goto pertamamulai;
                }
                else if (lajutya=='Y') {
                    goto pertamamulai;
                }



            }
    }
//}//dari choice

int main(){
    
	mainmenu();
}


//=====================Di indonesiakeun =====================
void terbilang(long x){ // Prosedur mengubah angka menjadi kata
/* I.S: x mengkonversi nilai x menjadi kata
F.S: nilai x berubah
*/
// Algoritma
    if(x==1){
    cout<<"Satu ";
    }else if(x==2){
    cout<<"Dua ";
    }else if(x==3){
    cout<<"Tiga ";
    }else if(x==4){
    cout<<"Empat ";
    }else if(x==5){
    cout<<"Lima ";
    }else if(x==6){
    cout<<"Enam ";
    }else if(x==7){
    cout<<"Tujuh ";
    }else if(x==8){
    cout<<"Delapan ";
    }else if(x==9){
    cout<<"Sembilan ";
    }else if(x==10){
    cout<<"Sepuluh ";
    }else if(x==11){
    cout<<"Sebelas ";
    }else if(x>=12&&x<=19){
    terbilang(x%10);
    cout<<"Belas ";
    }else if(x>=20&&x<=99){
    terbilang(x/10);
    cout<<"Puluh ";
    terbilang(x%10);
    }else if(x>=100&&x<=199){
    cout<<"Seratus ";
    terbilang(x-100);
    }else if(x>=200&&x<=999){
    terbilang(x/100);
    cout<<"Ratus ";
    terbilang(x%100);
    }else if(x>=1000&&x<=1999){
    cout<<"Seribu ";
    terbilang(x-1000);
    }else if(x>=2000&&x<=999999){
    terbilang(x/1000);
    cout<<"Ribu ";
    terbilang(x%1000);
    }else if(x>=1000000&&x<=999999999){
    terbilang(x/1000000);
    cout<<"Juta ";
    terbilang(x%1000000);
    }else if(x>=1000000000&&x<=2147483647){
    terbilang(x/1000000000);
    cout<<"Miliyar ";
    terbilang(x%1000000000);
    }
}

void getMenuPilihTransfer(){ // Menu Pilihan Transfer Dana
cout<<"-------------- TRANSFER DANA  ---------------\n";
cout<<" [1] Transfer Dana ke Rekening Bank Syariah  \n";
cout<<" [2] Transfer Dana ke Rekening Bank Lain     \n";
cout<<" [3] Kembali ke menu                         \n";
cout<<"---------------------------------------------\n";
}

void addElmTab(TabInt *T, int x){ // Prosedur untuk menambahkan Elemen pada sebuah Tabel yang terdapat pada tabel integer
/* I.S: T terisi sembarang, mungkin kosong
F.S: Bertambah 1 elemen bernilai x
*/
// Algoritma
    if((*T).nEff < nMax){
    (*T).nEff++;
    (*T).TI[(*T).nEff] = x;
    }
}
void cetakTabel(TabInt T){ // Prosedur untuk mencetak isi tabel pada tabel integer
/* I.S: T Terdefinisi sembarang
F.S: Semua elemen pada T dicetak
*/
// Variabel / Kamus
    int i;

// Algoritma
    i=1;
    while(i<=T.nEff){
    cout<<"<Rp. ->\n"<<T.TI[i];
    i++;
    }
}

