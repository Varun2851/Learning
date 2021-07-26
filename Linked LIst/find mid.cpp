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

void DeleteEnd(node*&head,node*&tail){
	 if(head==NULL){
	 	return;
	 }
	 else if(head->next == NULL){
	 	delete head; //only single node is present 
	 	head =tail = NULL;
	 }
	 else {
	 	node*temp = head;
	 	while(temp->next!= tail){
	 		temp = temp->next;
		 }
		 delete tail;
		 tail = temp;
		 tail->next = NULL;
	 }
}

node*Mid(node*head){
	if(!head){
		return head;
	}
	node*fast = head->next;
	node*slow = head;
	
	while(fast and fast->next){
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}

int main(){ 
	node*head = NULL;
	node*tail = NULL;
	InsertEnd(head,tail,1);
	InsertEnd(head,tail,2);
	InsertEnd(head,tail,3);
	InsertEnd(head,tail,4);
	InsertEnd(head,tail,5);
	//InsertEnd(head,tail,6);
//	DeleteEnd(head,tail);
	PrintLL(head);
	
	node*ans = Mid(head);
	
	if(ans != NULL){
		//node is found
		cout<<"Middle found "<<ans->data<<endl;
	}
	else{
		cout<<"Not found "<<endl;
	}
	
	return 0;	
}
