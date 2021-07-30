#include<iostream>
#include<queue>
using namespace std;

class node{
	public:
		int data;
		node*left;
		node*right;
		
		node(int d){
			data = d;
			left = NULL;
			right = NULL;
		}
};

node* Buildtree(){
	int data;
	cin>>data;
	if(data == -1){
		return NULL;
	}
	else{
		node *root = new node (data); // creating a new node
		root->left = Buildtree();
		root->right = Buildtree();
		return root;
	}
}

void Preorder(node *root){
	//base case
	if(root == NULL){
		return ;
	}
	//recursive case
	cout<<root->data<<" ";
	Preorder(root->left);
	Preorder(root->right);
}

void Inorder(node *root){
	//base case
	if(root == NULL) { 
	   return;
	}
	// recursive case
	//1.Print the left sub tree
	Inorder(root->left); 
	// 2. Print the root
	cout<<root->data<<" ";
	// 3. Print the right sub tree
	Inorder(root->right); 
	
}

void Postorder(node*root){
	// base case
	if(root == NULL) {
		return;
	}
	// recursive case
	// 1.print left
	Postorder(root->left);
	//2.print right
	Postorder(root->right);
	//3. print root
	cout<<root->data<<" ";
	
}

int countNodes(node*root){
	//base case
	if(root ==NULL){
		return 0;
	}
	//recursive case
	return countNodes(root->left) + countNodes(root->right) +1;  
}

int height(node *root){
	//base case
	if(root == NULL){
		return 0;
	}
	//recursive case
	int left_height = height(root->left);
	int right_height = height(root->right);
	return max(left_height ,right_height)+1;
}

int SumofBt(node *root){
	if(!root){
		return 0;
	}
	return SumofBt(root->left) + SumofBt(root->right) + root->data;
}

void Mirror(node *root){
	// base case;
	if (!root){
		return;
	}
	// recursive case
	swap(root->left , root->right);
	Mirror(root->left);
	Mirror(root->right);
}

///////////////////////// PRINT TREE LEVEL WISE///////////////

void PRINTLEVEL(node*root){
	queue<node*>q;
	q.push(root);
	q.push(NULL); 
	
	while (!q.empty()){
		node*x = q.front();
		q.pop();
		if(x == NULL){
			cout<<endl;
			if(!q.empty()){
				q.push(NULL);
			}
		}
		else{
			cout<<x->data<<" ";
			if(x->left != NULL){
				q.push(x->left); // x jo hamare node h uska left h to x k left ko queue m dal dia 
			}
			if(x->right != NULL){
				q.push(x->right); // x k right k children h unko dal do queue m
			}
			
		}
	}
}

//////////////////////CREATE TREE LEVEL WISE//////////////////
node* BuildTreeLevel() {
	node* root = NULL; // initially root m NULL hoga.
	int data;
	cout << "Enter root data "; // usre ne data dia
	cin >> data;
	if (data == -1) {
		return NULL;
	}
	root = new node(data); // data ko root m insert kr dia 

	queue<node*> q;
	q.push(root);
	while (!q.empty()) {
		node* x = q.front();
		q.pop();

		cout << "Enter data of " << x->data << endl;
		int left_data, right_data;
		cin >> left_data >> right_data;
		if (left_data != -1) {
			x->left = new node(left_data);
			q.push(x->left);
		}
		if (right_data != -1) {
			x->right = new node(right_data);
			q.push(x->right);
		}
	}

	return root;
}

//////////////////CREATE TREE FROM INORDER AND PREORDER/////////////

int pre[] = {8, 3, 1, 6, 4, 7, 10, 14, 13}; // ROOT LEFT RIGHT
int i = 0; // ITERATOR LIA H JO PRE WALE ARRAY PAR MOVE KARAIGA
int in[] = {1, 3, 4, 6, 7, 8, 10, 13, 14}; // LEFT ROOT RIGHT

node*CREATETREE(int s, int e){
	// base case 
	if(s > e){
		return NULL;
	}
	
	// recursive case
	int  d = pre[i];
	i++;
	node * root = new node (d); // pre order k 1st indx pe jo value h usko root node bna dia
	int k = -1; // initially index ko -1 man lia
	for(int j = s; j<=e; j++){
		if(in[j] == d){
			k = j;
			break;
		}
	}
	root->left = CREATETREE(s, k-1);
	root->right =CREATETREE(k+1,e);
	return root;
	
}


int main(){

	//node *root = Buildtree();
	
	int n = sizeof(in) / sizeof(int);
	node* root = CREATETREE(0, n - 1); 
	

	Inorder(root); 
	cout<<endl;
	Preorder(root);
	cout<<endl;
	Postorder(root);
	cout<<endl;

	
   // node *root = BuildTreeLevel() ;
    
	//PRINTLEVEL(root);
	
	
	
//	cout<<"Total nodes count :"<<countNodes(root)<<endl; 
//	cout<<"Height :"<<height(root)<<endl; 
//	cout<<"Sum of Tree :"<<SumofBt(root)<<endl; 
//	Mirror (root);
	
	
	return 0; 
}
