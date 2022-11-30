#include <iostream>
#include <vector>
#include <list>
#include <iterator>
using namespace std;

/*Implement a recursive function reverseOutput that outpust the elements in the iterator range (first,last)
in reverse order.
*/
void reverseOutput(list <int> :: iterator first, list <int>::iterator last){
	
	
	while(1){
		if(last != first){
		cout<<*last<<" ";
		last--;
		reverseOutput(first,last);
		break;
	}
	else if (first == last){
		cout<<*first;
		break;
	}
}
}


int main(){
	int arr[] = {1,2,3,4};
	
	int size = sizeof(arr) / sizeof(int);
	list <int> myList(arr,arr+size);
	
	
	
	list <int> ::iterator first=myList.begin();
	list <int> ::iterator last=myList.end();
	last--;
	
	reverseOutput(first,last);
	
}
		
		
		
		
		
		
		

	
	
	
	
	
	

