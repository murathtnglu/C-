#include <iostream>
#include <vector>
#include <list>
#include <iterator>
using namespace std;

/*Implement two version of the reverseVector() Function ,which reverses the order of elements in a vector
*/

template <typename T>
void reverseVector1(vector <T> &v){
	
	int n = v.size(), j=0;
	
	T temp;
	
	while(n >= j){
		temp = v[j];
		v[j] = v[n-1];
		v[n-1] = temp;
		j++;
		n--;
	}  
	
}

int main(){
	
	int arr[8] = {1,2,3,4,5,6,7,8};
	
	vector <int> vector(arr , arr+8);
	
	reverseVector1(vector);
	
	for(int i = 0 ; i < vector.size();i++){
		cout<<vector[i]<<endl;
	}
	return 0;
}
