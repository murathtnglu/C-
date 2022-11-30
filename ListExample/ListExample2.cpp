#include <iostream>
#include <list>
#include <iterator>

using namespace std;

int count( list<int> &aList , const int &item){
	
	int count = 0;
	
	typename list<int>::iterator iter = aList.begin();
	
	while(iter != aList.end()){
		if(item == *iter){
			count++;
		}
		iter++;
	}
	return count;
}


int main(){
	int num;
	int arr[] = {1,2,3,3,4,4,4,5};
	int arrSize = sizeof(arr) / sizeof(int);
	list<int> l(arr,arr+arrSize);
	
	num = count(l,4);
	cout<<num;
	
	return 0;
}
