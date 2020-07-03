#include <iostream> 
using namespace std;


struct mahasiswa {
	int npm;
	string nama;
	float nilai;

};
mahasiswa  data[30];

int masuk; int n; int x; int temp; int del; int edit;


	

int main() {
	
cout << "Menu :" << endl;
cout << "1. Tambah Data MHS\n";
cout << "2. Edit Data\n";
cout << "3. Hapus Data\n";
cout << "4. Sorting Data\n";
cout << "5. Tampilkan Data\n";
cout << "6. Exit\n" << endl;
cout << "Masukkan : "; cin >> masuk; 
	
switch (masuk) 
	{
	case 1: 		 
		cout << "Masukkan data yang akan diinput : "; 
		cin >> n; 
			for (x=1; x<=n; x++) {
				cout << "\nNPM		: "; 
				cin >>  data[x].npm; 
				cout << "\nNama		: "; 
				cin >>  data[x].nama;
				cout << "\nNilai		: "; 
				cin >>  data[x].nilai;			
				}; 
		case 2:
			cout << "\nMasukkan NPM Mahasiswa : "; 
			cin >> edit;
			for(x=1; x<=n; x++) 
			{
                if (edit ==  data[x].npm) 
                {
                cout << "\nData Baru : ";
                    cout << "\nNPM	: "; 
                    cin >>  data[x].npm;
                    cout << "\nNama	Mahasiswa : "; 
                    cin >>  data[x].nama;
                    cout << "\nNilai   : "; 
                    cin >>  data[x].nilai;
      
                    cout<< edit<< " telah berhasil di ubah\n";
					
                }
                
                
			}
    case 3:
	  
            cout << "\nMasukkan NPM akan di delete : "; 
            cin >> del;
                for(x=1; x<=n; x++) 
                {
                    if (del ==  data[x].npm) 
                    {
                    cout<< del << " telah di hapus" << endl;
                        for (int k = x; k < n; k++) {
                         data[k].npm =  data[k+1].npm;
                        }
                    }
               
            }
            
	
		case 4:
			for (x=0; x < n; x++)
			{
           for (int j = x+1; j < n; j++)
           {
                    if ( data[x].npm >  data[j].npm)
                    {
                        temp =  data[x].npm;
                         data[x].npm =  data[j].npm;
                         data[j].npm = temp;
                    }
                }
            cout << "NPM: \n" << data[x].npm;
			cout << "Nama:\n" << data[x].nama;
			cout << "Nilai: \n" << data[x].nilai;
            }
	
	case 5:
			for (x=1; x<=n; x++) 
			{
				cout << "NPM :\n" << data[x].npm; 
				cout << "Nama :\n" << data[x].nama;
				cout << "Nilai :\n" << data[x].nilai; 
			}
		
		
		case 6: return 0;
	
	}
	
}
