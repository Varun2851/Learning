#include <iostream>
#include <vector>
using namespace std;

class node {
public:
	int data;
	node* next; // self referential class

	node(int d): data(d), next(NULL) {}
};

void InsertAtEnd(node* &head,  int data) {
	node* n = new node(data);
	if (head == NULL) {
		// We are inserting the first node
		head =  n;
	}
	else {
		// We have linkedList
		node*temp = head;
		while(temp->next){
			temp = temp->next;
		}
		temp->next = n;
	}
}

void Reverse(node*&head){
	
	node*c = head, *previous =NULL, *n; // c ko head pe ,previous ko null pe set kia h and n sirf ek pointer h.
	while(c){
		n = c->next;
		c->next = previous;
		previous = c;
		c = n;
	}
	head = previous;
	
	
}
void PrintLL(node* head) {
	while (head) {
		cout << head->data << "-->";
		head = head->next;    
	}
	cout << "NULL" << endl;
}
int main() {
	 node* head = NULL;

	 InsertAtEnd(head,1);
	 InsertAtEnd(head,1);
	 InsertAtEnd(head,1);
	 InsertAtEnd(head,1);
	 InsertAtEnd(head,2);
	 InsertAtEnd(head,3);
	 InsertAtEnd(head,3);
	 InsertAtEnd(head,3);
	 InsertAtEnd(head,3);
	 InsertAtEnd(head,3);

    

	 PrintLL(head);

     Reverse(head);
     PrintLL(head);
   

	return 0;
}



