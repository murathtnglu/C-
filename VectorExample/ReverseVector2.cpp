#include <iostream>
#include <vector>
#include <list>
#include <iterator>
using namespace std;

/*
Copy the elements of v in reverse to the vack of a new vector, and return the new vector
*/

template <typename T>
vector <T> reverseVector(const vector<T> &v){
	
	vector <T>  new_vec;
	
	for(int i = v.size()-1; i>=0;i--){
		new_vec.push_back(v[i]);
	}
	return new_vec;
}


int main(){
	int arr[4] = {1,2,3,4};
	
	int size = sizeof(arr) / sizeof(int);
	
	vector <int> v(arr , arr+size);
	vector <int> nev_vec = reverseVector(v);
	
	for(int i = 0 ; i < nev_vec.size(); i++){
		cout<<nev_vec[i]<<endl;
	}
}
