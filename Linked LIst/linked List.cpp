//INSERTATFRONT
#include <iostream>
#include <vector>
using namespace std;

class node {
public:
	int data;
	node* next; // self referential class

	node(int d): data(d), next(NULL) {}
};

void InsertAtFront(node* &head, node* &tail, int data) {
	node* n = new node(data);
	if (head == NULL) {
		// We are inserting the first node
		head = tail = n;
	}
	else {
		// We have linkedList
		n->next = head;
		head = n;
	}
}
void PrintLL(node* head) {
	while (head) {
		cout << head->data << "-->";
		head = head->next;
	}
	cout << "NULL" << endl;
}


int main() {



	node* head = NULL, *tail = NULL;
	 InsertAtFront(head,tail,1);
	 InsertAtFront(head,tail,2);
	 InsertAtFront(head,tail,3);

	 PrintLL(head);



	return 0;
}

