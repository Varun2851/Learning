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

node*SearchRec(node*head,int d){ // return type is node* because we have to return address from the function
	//base case
	if(!head){
		return NULL;
	}
	//recursive case
	if(head->data == d){
		return head;
	}
	node * chotaAns = SearchRec(head->next,d);
	return chotaAns;
	return SearchRec(head->next,d); // we can do this also
}
 
node*SearchItr(node*head,int key){ //here we are searching iteratively
	while(head){
		if(head->data==key){
			return head;
		}
		head = head->next;
	}
	return NULL;
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
	
	node*ans = SearchRec(head,10); // here we are storing the address of found node in pointer named ans Ex Car.
	if(ans != NULL){
		// node is found
		cout<<"Node found  "<<ans->data<<endl;
	}
	else{
		cout<<"Node is not found"<<endl;
	}
	
	  ans = SearchItr(head,8);
	if(ans != NULL){
		//node is found
		cout<<"Node found "<<ans->data<<endl;
	}
	else{
		cout<<"Node is not found"<<endl;
	}
	
	
	return 0;	
}
