#include <iostream>
#include <vector>
using namespace std;

class node {
public:
	int data;
	node* next; // self referential class

	node(int d): data(d), next(NULL) {}
};

void InsertAtEnd(node* &head, node* &tail, int data) {
	node* n = new node(data);
	if (head == NULL) {
		// We are inserting the first node
		head = tail = n;
	}
	else {
		// We have linkedList
		tail -> next = n;
		tail = n;
	}
}
void PrintLL(node* head) {
	while (head) {
		cout << head->data << "-->";
		head = head->next;
	}
	cout << "NULL" << endl;
}

int length(node*head){ //passing head by value so that head loose na ho.
	int cnt = 0;
	while(head){
		head = head->next;
		cnt++;
	}
	return cnt;
}


 void bubblesort(node*&head){
 	int len = length(head);
 	node*c,*n,*prev;
 	for(int itr = 1; itr<=len-1; itr++){
 		c = head ;
 		prev = NULL;
 		while(c and c->next){
 			n = c->next;
 			if(c->data > n->data){
 				//swapping hogi
 				if(prev==NULL){
 					//head change hoga
 					c->next = n->next;
 					n->next = c;
 					prev = head = n;
				 }
				 else{
				 	//head chnage nh hoga
				 	c->next = n->next;
				 	n->next = c;
				 	prev->next = n;
				 	prev = n;
				 }
			 }
			 else{
			 	// swapping nhi hogi
			 	prev = c;
			 	c = n;
			 }
		 }
	 }
 }


int main() {
	 		node* head = NULL, *tail = NULL;

		 		InsertAtEnd(head,tail,5);
				 InsertAtEnd(head,tail,2);
				 InsertAtEnd(head,tail,3);
		 		InsertAtEnd(head,tail,3);
				 InsertAtEnd(head,tail,12);
				 InsertAtEnd(head,tail,17);
		 	InsertAtEnd(head,tail,3);
		 	InsertAtEnd(head,tail,2000);
	
		 PrintLL(head);
		 bubblesort(head);
		 PrintLL(head);
		 
		 return 0;
}



