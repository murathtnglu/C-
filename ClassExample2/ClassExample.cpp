#include <iostream>
#define pi 3.14
using namespace std;



class Daire{
	
	float yaricap;
	
	public:
		void setYariCap(float r){
			yaricap = r;
		}
		
		float getAlan(){
			float alan;
			alan = pi*yaricap*yaricap;
			return alan;
		}
		
		float getCevre(){
			float cevre;
			cevre = 2*pi*yaricap;
			return cevre;
		}
};





int main(){
	float r1,r2;
	Daire daire1,daire2;
	
	cout<<"Birinci yaricap girin : "<<endl;
	cin>>r1;
	daire1.setYariCap(r1);
	cout<<"Alan: "<<daire1.getAlan()<<endl;
	cout<<"Cevre : "<<daire1.getCevre()<<endl;
	
	cout<<"Ikinci yaricap girin : ";
	cin>>r2;
	daire2.setYariCap(r2);
	cout<<"Alan: "<<daire1.getAlan()<<endl;
	cout<<"Cevre : "<<daire1.getCevre()<<endl;
	
	
	if(daire1.getCevre() >daire2.getCevre()){
		cout<<"Daire 1 daha buyuk";
	}
	else{cout<<"Daire 2 daha buyuk";}
	

	
	
}
