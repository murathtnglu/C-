#include <iostream>
#include "Sekil.h"
#include <string>
using namespace std;
int main(int argc, char** argv) {
	int x,y,gen;
	char secim;
	cout<<"Genislik ve Yukseklik giriniz : ";
	cin>>x>>y;
	
	
	Sekil obje(x,y);
	obje.Ciz();
	do{
		cout<<"G - Genislik Degistir\n";
		cout<<"C - Cikisi";
		cout<<"\n Seciminiz : ";
		cin>>secim;
		
		
		
		switch(secim){
		case 'G':
			cout<<"\n Yeni genisligi girin : ";
			cin>>gen;
			obje.GenislikDuzelt(gen);
			obje.Alan();
			obje.Ciz();
			break;	
		}
	}while (secim != 'C');
	cout<<"Bye...";
	
	return 0;
}
