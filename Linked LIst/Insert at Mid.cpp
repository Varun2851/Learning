#include<iostream>
using namespace std;

class node{
	public:
	int data;
	node*next;
	
	node(int d):data(d),next(NULL){
	} 
};

void InsertFront(node*&head,node*&tail,int data){
	node*n = new node(data);
	// creating a new node dynamically , if we create statically our node will automatically destroy after our scope will end
	 
	if(head == NULL){
		head = tail = n;
	}
	else{
		n->next = head;
		head = n ;
	}
	 
}

void InsertMid(node*&head,node*&tail , int data , int pos){
	if(pos == 0){
		InsertFront(head,tail,data);
	} 
	else{
		node*n = new node(data);
		node*temp = head;
		for(int i = 1; i<=pos-1; i++){
			temp = temp->next;
		}
		n->next = temp->next;
		temp->next = n;
	}
}

void PrintLL(node*head){
	while(head){
		cout<<head->data<<"->";
		head = head->next;
	}
	cout<<"NULL"<<endl;
}

void DeleteMid(node*&head,node*&tail,int pos){
	 if(head==NULL){
	 	return;
	 }
	 else if(head->next==NULL){
	 	delete head;
	 	head = tail = NULL;
	 }
	 else{
	 	node*temp = head;
	 	for(int i =1; i<pos ; i++){
	 		temp = temp->next;
		 }
		 node*n = temp->next; // we are storing the address of node which we want to delete in n pointer so that it may not lose.
		 temp->next = n->next ;
		 delete n;
	 }
}


int main(){
	node*head = NULL;
	node*tail = NULL;
	InsertFront(head,tail,1);
	InsertFront(head,tail,2);
	InsertFront(head,tail,3);
	InsertFront(head,tail,4);
	
	PrintLL(head);
	InsertMid(head,tail,5,2);
	DeleteMid(head,tail,2);
	PrintLL(head);
	DeleteMid(head,tail,1);
	PrintLL(head);
	
	return 0;	
}
