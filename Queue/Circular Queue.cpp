#include<iostream>
using namespace std;
class node{
	public:
		int data;
		node*next;
		
		node(int d){
			data = d ;
			next = NULL;
		}
};

class Queue{
    int *arr;
    int f ,e ,n, curr_size;
	int len;
	public:
	     Queue(int s =5){
	     	arr = new int[s];
	     	n = s;
	     	f =0;
	     	e = n-1;
	     	curr_size = 0;
		 }
		
		void push(int data){
			if(curr_size<n){
			e = (e+1)%n;
			arr[e] = data;
			curr_size ++;
		}
		else{
			cout<<"Queue overflow"<<endl;
		}
		}
		
		void pop(){
	          if(curr_size>0){
	          	f = (f+1)%n;
	          	curr_size--;
			  }
			  else{
			  	cout<<"Queue underflow"<<endl;
			  }
		}
		
		int front(){
			return arr[f];
		  }
		  
		bool empty(){
		     return curr_size==0;
		}
		
		int size(){
		      return curr_size;
		}
};
int main(){
	
	// Queue q;
	Queue q(7); // if we want to  insert more element than 5
	
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(4);
	q.push(4);
	q.push(4);
	
	while(!q.empty()){
		cout<<q.front()<<" ";
		q.pop();
	}
	cout<<endl;
	return 0;	
}
