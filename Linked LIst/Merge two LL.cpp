#include <iostream>
#include <vector>
using namespace std;

class node {
public:
	int data;
	node* next; // self referential class

	node(int d): data(d), next(NULL) {}
};

void InsertAtEnd(node* &head, int data) {
	node* n = new node(data);
	if (head == NULL) {
		// We are inserting the first node
		head = n;
	}
	else {
		// We have linkedList
		node* temp = head;
		while (temp->next) {
			temp = temp->next;
		}
		temp->next = n;
	}
}

void PrintLL(node* head) {
	while (head) {
		cout << head->data << "-->";
		head = head->next;
	}
	cout << "NULL" << endl;
}

node* merge(node* a, node* b) {
	// base case
	if (a == NULL) {
		return b;
	}
	if (b == NULL) {
		return a;
	}

	// recursive case
	node* newHead; //we are making a new pointer named newhead
	if (a->data < b->data) {
		newHead = a;
		node* c = merge(a->next, b);
		newHead->next = c;
	}
	else {
		newHead = b;
		node* c = merge(a, b->next);
		newHead->next = c;
	}
	return newHead;
}

int main(){
	
node*head = NULL;
node*head1 = NULL;

InsertAtEnd(head,1);	
InsertAtEnd(head,2);	
InsertAtEnd(head,3);	
InsertAtEnd(head,5);	
InsertAtEnd(head,7);	
InsertAtEnd(head,9);

PrintLL(head);

InsertAtEnd(head1 ,2);	
InsertAtEnd(head1 ,10);	
InsertAtEnd(head1 ,20);	
InsertAtEnd(head1 ,21)	;
InsertAtEnd(head1 ,22);	
InsertAtEnd(head1 ,23);	

PrintLL(head1);

node*newhead = merge(head,head1);
PrintLL(newhead);
return 0;	 	
}


