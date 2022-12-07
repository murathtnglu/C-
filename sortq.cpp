#include <iostream>
#include <queue>
#include<cstdlib>
#include<ctime>
using namespace std;

/* The function sortqueue sorts a queue using priority queue 
and the function printqueue simply prints a queue =)*/

template<typename T>
void sortqueue(queue<T> &q){
	priority_queue<T> prque;
	queue<T> temp(q);

	for(int i = 0 ; i<q.size() ; i++){
		prque.push(temp.front());
		temp.pop();
	}
	while(!prque.empty()){
		cout << prque.top() <<" ";
		prque.pop();
	}	
	
}

template<typename T>
void printqueue(queue<T> &q){
	
	queue<T> temp(q);
	while(!temp.empty()){
		cout << temp.front() <<" ";
		temp.pop();
	}	
}


int main(){
	
	queue<int> q;
	int rand_num;
	srand(time(NULL));
	
	for(int i = 0 ; i < 10; i++){
		rand_num = rand()%100 + 1;
		q.push(rand_num);
	}
	
	cout << "First version of the queue: " << endl;
	printqueue(q);
	
	cout << "\nLast version of the queue: " << endl;
	sortqueue(q);
	
	return 0;
}
