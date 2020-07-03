#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

string s1,s2,s3,s4, copy1,copy2;
int pilih;

int main() {
		
	system("clear");
	cout << "1. copy\n";
	cout << "2. concatenate\n";
	cout << "3. compare\n";
	cout << "4. length\n";
	cout << "5. chr\n";
	cout << "6. str\n";
	
	cout << "Pilih : "; cin >> pilih;
	
	switch(pilih) {
		case 1 :
			cout << "Masukkan string 1 : \n"; cin >> s1;
			cout << "Masukkan string 2 : \n"; cin >> s2;
			
			copy1 = strcpy(s4,s2);
			copy2 = strcpy(s4,s2);
			
			cout << "Copy string 2 ke string 4 : " << s4 <<endl;
			cout << "Copy string 1 ke string 2 : " << s3 <<endl;
		case 2 :
			cout << "Masukkan string 1 : "; cin >> s1;
			cout << "Masukkan string 2 : "; cin >> s2;
			cout << "Copy string 2 ke string 1 : " << strcpy(s1,s2) <<endl;
			
	}	
	return 0;
}
