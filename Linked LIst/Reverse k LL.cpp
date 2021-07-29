//https://hack.codingblocks.com/app/contests/2022/1326/problem (problem link)

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
void PrintLL(node* head) {
	while (head) {
		cout << head->data << "-->";
		head = head->next;    
	}
	cout << "NULL" << endl;
}

node*reversek(node*head , int k){
	node * previous = NULL;
	node * current = head;
	node * next;
	int count =0;
	
	while(current != NULL and count<k){
		next  = current->next;
		current->next = previous ;
		previous = current;
		current = next;
		count++;
	}
	//head = previous ;
	
	if(current != NULL){
		head->next = reversek(next ,k);
	}
	return previous;
	
}

int main() {
	 node* head = NULL;

//	 InsertAtEnd(head,1);
//	 InsertAtEnd(head,1);
//	 InsertAtEnd(head,1);
//	 InsertAtEnd(head,1);
//	 InsertAtEnd(head,2);   sir aise kia krte thai insert
//	 InsertAtEnd(head,3);
//	 InsertAtEnd(head,3);
//	 InsertAtEnd(head,3);
//	 InsertAtEnd(head,3);
//	 InsertAtEnd(head,3);
	 
     int a; // ye data h matlab jo user dega jaise 1 ,2 ,3 ....
     int n; // n denote krta h ki hme kitne no lene h ll m 4 6 ya 8 jo bhi ho
     cin>>n;
     int k; // k denote krta h ki kitne no. ek bar m reverse krne h 
     cin>>k;
    for(int i =0; i<n; i++){
    	cin>>a; // aise lete h user se input 
    	InsertAtEnd(head ,a); // ll m input krne k liye 2 method hote h  ya to insert head se kr lo ya phir tail se tail matlab end se 
    	// to yha pe tail se insert kia gya h .. ek ek krkai user values dega aur ham usko apne function banaya h usme dalte jayaigai.
	}

    node*newhead = reversek(head,k);
    PrintLL(newhead); 


	return 0;
}











