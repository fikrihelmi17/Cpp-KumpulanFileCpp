#include <conio.h>
#include <iostream>
#include <malloc.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>

using namespace std;

struct node {
	char idPasien[5];
	char nama[20];
	char jenisKelamin[2];
	char jenisPasien[20];
	int usia;
	node *next;
} pasien;

class list
{
	private:
	node *head, *tail;	
	public:
	list()
	{
		head = NULL;
		tail = NULL;
	}
	
	void createnode(node pasien)
	{
		node *temp = new node;
		strcpy(temp->idPasien, pasien.idPasien);
		strcpy(temp->nama, pasien.nama);
		strcpy(temp->jenisKelamin, pasien.jenisKelamin);
		strcpy(temp->jenisPasien, pasien.jenisPasien);
		temp->usia = pasien.usia;
		temp->next = NULL;
		
		if(head == NULL)
		{
			head = temp;
			tail = temp;
			temp = NULL;
		}
		else
		{	
			tail->next = temp;
			tail = temp;
		}
	}
	
	void insert_start(node pasien)
	{
		node *temp = new node;
		strcpy(temp->idPasien, pasien.idPasien);
		strcpy(temp->nama, pasien.nama);
		strcpy(temp->jenisKelamin, pasien.jenisKelamin);
		strcpy(temp->jenisPasien, pasien.jenisPasien);
		temp->usia = pasien.usia;
		temp->next = head;
		head = temp;
	}
	
	void display()
	{
		node *temp = new node;
		temp = head;
		
		while(temp != NULL)
		{
			cout << "ID Pasien : " << temp->idPasien << "\n";
			cout << "Nama Pasien : " << temp->nama << "\n";
			cout << "Jenis Kelamin : " << temp->jenisKelamin << "\n";
			cout << "Jenis Pasien : " << temp->jenisPasien << "\n";
			cout << "Usia : " << temp->usia << "\n";
			temp = temp->next;
		}
	}
	
	void search(char search[20])
	{
		node *temp = new node;
		temp = head;
		while(temp != NULL)
		{
			if(strcmp(temp->idPasien, search) == 0)
			{
				cout << "ID Pasien : " << temp->idPasien << "\n";
				cout << "Nama Pasien : " << temp->nama << "\n";
				cout << "Jenis Kelamin : " << temp->jenisKelamin << "\n";
				cout << "Jenis Pasien : " << temp->jenisPasien << "\n";
				cout << "Usia : " << temp->usia << "\n";
				
				temp = NULL;
			} else {
				temp = temp->next;	
			}
		}
	}
	
	void deletion(int pos)
	{
		node *current = new node;
		node *previous = new node;
		current = head;
		
		for(int i = 1; i < pos; i++)
		{
			previous = current;
			current = current->next;
		}
		
		previous->next = current->next;
		
	}
	
	void minmax()
	{
		int min, max;
		node *temp, *young, *old = new node;
		temp = head;
		
		int i = 0;
		while(temp != NULL)
		{
			if(i == 0)
			{
				min = temp->usia;
				max = temp->usia;
			}
			else if(min > temp->usia)
			{
				young = temp;
			}
			else if(max < temp->usia)
			{
				old = temp;
			} 
			else {}
			
			i++;
			temp = temp->next;
		}
		
		cout << "Data Pasien dengan Usia Termuda : \n";
		cout << "ID Pasien : " << young->idPasien << "\n";
		cout << "Nama Pasien : " << young->nama << "\n";
		cout << "Jenis Kelamin : " << young->jenisKelamin << "\n";
		cout << "Jenis Pasien : " << young->jenisPasien << "\n";
		cout << "Usia : " << young->usia << "\n\n";
		
		cout << "Data Pasien dengan Usia Tertua : \n";
		cout << "ID Pasien : " << old->idPasien << "\n";
		cout << "Nama Pasien : " << old->nama << "\n";
		cout << "Jenis Kelamin : " << old->jenisKelamin << "\n";
		cout << "Jenis Pasien : " << old->jenisPasien << "\n";
		cout << "Usia : " << old->usia << "\n";
	}
};

int pilih, n, pos;
char search[20];
list obj;

int main()
{
	do
	{
		cout << "\n**********************************\n";
		cout << "*  M E N U   U T A M A           *\n";
		cout << "* 1. Add Data (di akhir)         *\n";
		cout << "* 2. Add Data (di awal)          *\n";
		cout << "* 3. View Data                   *\n";
		cout << "* 4. Search Data                 *\n";
		cout << "* 5. Delete Data                 *\n";
		cout << "* 6. Min & Max Value  -- Bonus   *\n";
		cout << "* 7. Exit                        *\n";
		cout << "**********************************\n";
		cout << "Pilih Menu [1/2/3/4/5/6/7] : "; cin >> pilih;
		
		switch(pilih)
		{
			case 1 : /*1. Add Data (di akhir)*/
			{
				cout << "\nMasukkan jumlah data pasien : "; cin >> n;
				
				for(int i = 0; i < n; i++)
				{
					cout << "Data Pasien ke-" << i+1 << "\n";
					cout << "ID Pasien : "; cin >> pasien.idPasien;
					cout << "Nama Pasien : "; cin >> pasien.nama;
					cout << "Jenis Kelamin (L/P) : "; cin >> pasien.jenisKelamin;
					cout << "Jenis Pasien : "; cin >> pasien.jenisPasien;
					cout << "Usia : "; cin >> pasien.usia;
					
					obj.createnode(pasien);
				}
			}
			break;
			
			case 2 : /*2. Add Data (di awal)*/
			{
				cout << "\nMasukkan jumlah data pasien : "; cin >> n;
				
				for(int i = 0; i < n; i++)
				{
					cout << "Data Pasien ke-" << i+1 << "\n";
					cout << "ID Pasien : "; cin >> pasien.idPasien;
					cout << "Nama Pasien : "; cin >> pasien.nama;
					cout << "Jenis Kelamin (L/P) : "; cin >> pasien.jenisKelamin;
					cout << "Jenis Pasien : "; cin >> pasien.jenisPasien;
					cout << "Usia : "; cin >> pasien.usia;
					
					obj.insert_start(pasien);
				}
			}
			break;
			
			case 3 : /*3. View Data*/
			{
				obj.display();
			}
			break;
			
			case 4 : /*4. Search Data*/
			{
				cout << "Mencari Data Pasien berdasarkan ID Pasien\n";
				cout << "ID Pasien : "; cin >> search;
				
				obj.search(search);
			}
			break;
			
			case 5 : /*5. Delete Data*/
			{
				cout << "Menghapus Data Pasien berdasarkan Posisi\n";
				cout << "Posisi : "; cin >> pos;
				
				obj.deletion(pos);
			}
			break;
			
			case 6 :/*6. Min & Max Value  -- Bonus*/
			{
				cout << "Menampilkan Data Pasien Usia Termuda dan Tertua\n";
				obj.minmax();
			}
			break;
			
			case 7 : cout<<"End of Application!!!";getch();break;
			default : cout<<"Salah pilih !!!";getch();break;
		
		}

	} while (pilih >= 1 && pilih <= 6);
	
	return 0;
}
