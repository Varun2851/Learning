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

void DeleteFront(node*&head,node*&tail){
	if(head==NULL){
		return;
	}
	else if(head->next==NULL){ // if only single node is present 
	   delete head;
	   head = tail = NULL;
	}
	else{
		node*n = head; // we are creating a pointer n which is pointing to head so that if we move head pointer ,head pointer will not lost
		head = head->next;
		delete n ;
	}
}


void PrintLL(node*head){
	while(head){
		cout<<head->data<<"->";
		head = head->next;
	}
	cout<<"NULL"<<endl;
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
	PrintLL(head);
	DeleteFront (head,tail);
	PrintLL(head);
	
	return 0;	
}
