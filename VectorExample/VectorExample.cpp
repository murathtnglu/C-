#include <iostream>
#include <vector>
#include <list>
#include <iterator>
using namespace std;


//lab soru 13
/*The template-based fucntion pop_front() erases the first element in a vector and returns
its value.Ýt throws the underflowError exception if v is empty.
*/

template <typename T>
T pop_front(vector<T>& v){
	int value;
	if(v.size() > 0){
		value = v[0];
		v.erase(v.begin());
		return value;
	}
	else{
		cout<<"empty";
	}
}


int main(){
	int first;
	int arr[4] = {1,2,3,4};
	
	int size = sizeof(arr) / sizeof(int);
	
	vector<int> v(arr,arr+size);
	

	
	first=pop_front(v);
	
	cout<<first<<endl;
	
	for(int i = 0 ; i < v.size(); i++){
		cout<<v[i]<<" ";
	}
	
}
