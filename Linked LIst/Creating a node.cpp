#include<iostream>
using namespace std;

class node{
	public:
	int data;
	node*next;
	
	node(int d):data(d),next(NULL){
	} 
};

int main(){
	node n1(1);
	node n2(2);
	
	n1.next = &n2;
	
	cout<<n1.data<<"-->"<<n2.data <<endl;
	
	return 0;
}
