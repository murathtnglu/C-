#include "Sekil.h"
#include <iostream>

using namespace std;

Sekil::Sekil(int g , int y){
	genislik = g;
	yukseklik = y;
}

void Sekil::GenislikDuzelt(int w){
	genislik = w;
}


void Sekil::SekilSoyle(){
	if(genislik == yukseklik){
		cout<<"Sekil Karedir";
	}
	else
	{
		cout<<"Sekil Dortgendir";
	}
}

void Sekil::Alan(){
	cout<<"Alan : "<<genislik*yukseklik;
}

void Sekil::Ciz(){
	for(int i = 0 ; i < yukseklik ; i++){
		for(int j = 0 ; j < genislik ; j++){
			cout<<"*";
		}
		cout<<endl;
	}
}
