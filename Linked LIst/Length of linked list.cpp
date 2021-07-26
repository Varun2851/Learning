#include<iostream>
using namespace std;

class node{
	public:
	int data;
	node*next;
	
	node(int d):data(d),next(NULL){
	} 
};

void InsertEnd(node*&head,node*&tail,int data){
	node*n = new node(data);
	// creating a new node dynamically , if we create statically our node will automatically destroy after our scope will end
	 
	if(head == NULL){
		head = tail = n;
	}
	else{
		tail->next = n;
		tail = n;
		
	}
	 
}

void PrintLL(node*head){
	while(head){ 
		cout<<head->data<<"->";
		head = head->next;
	}
	cout<<"NULL"<<endl;
}

int length(node*head){ //passing head by value so that head loose na ho.
	int cnt = 0;
	while(head){
		head = head->next;
		cnt++;
	}
	return cnt;
}

// length of linkedlist recursively

int LenRec(node*head){
	// base case
	if(!head){
		return 0;
	}
	//recursively
	return 1+LenRec(head->next);
}


int main(){
	node*head = NULL;
	node*tail = NULL;
	InsertEnd(head,tail,1);
	InsertEnd(head,tail,2);
	InsertEnd(head,tail,3);
	InsertEnd(head,tail,4);
	InsertEnd(head,tail,5);
	
	PrintLL(head);
	
	cout<<length(head)<<endl;
	cout<<LenRec(head)<<endl;
	
	return 0;	
}
