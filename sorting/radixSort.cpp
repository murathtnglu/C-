#include <iostream>
#include <vector>
#include<queue>
#include<cstdlib>
#include<ctime>
using namespace std;


void distribute(const vector<int> &v , queue<int> digitQueue[], int power ){
	for(int i = 0 ; i < v.size() ; i++){
		digitQueue[(v[i]/ power)  % 10].push(v[i]);
		
	}
}

void collect (queue<int> digitQueue[], vector<int> &v){
	int i = 0;
	
	for(int digit = 0 ; digit < 10 ; digit++){
		while(!digitQueue[digit].empty()){
			v[i] = digitQueue[digit].front();
			digitQueue[digit].pop();
			i++;
		}
	}
}

void radixSort(vector<int> &v, int d){
	int power = 1 ;
	queue<int> digitQueue[10];
	
	for(int i = 0 ; i <d ; i++){
		distribute(v,digitQueue , power);
		collect(digitQueue,v);
		power *=10;
	}
}

template<typename T>
void writeVector(const vector<T> &v){
	for(int i = 0 ; i < v.size() ; i++)
		cout << v[i] << " ";
	cout << endl;
}


int main(int argc , const char *argv[]){
	vector<int> Avec;
	srand(time(NULL));
	for(int i = 0 ; i < 20 ; i++){
		Avec.push_back(rand() % 100);
	}
	
	writeVector(Avec);
	radixSort(Avec,20);
	writeVector(Avec);
	
	return 0;	
	
}


