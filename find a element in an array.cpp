#include<iostream>
using namespace std;
int main (){
	int arr[100][100];
	int r,c;
	cin>>r>>c;
	for(int i =0; i<r; i++){
		for(int j =0; j<c; j++){
			cin>>arr[i][j];
		}
	}
	int key,i j;
	cin>>key;
	for(int i =0; i<r; i++){
		for(int j=0; j<c; j++){
			if(arr[i][j]==key){
				cout<<"key found at"<<i<<j<<endl;
				break;
			}
		}
		if(j!=c){
			break;
		}
	}
	if(i==r){
		cout<<"Key not found"<<endl;
	}
	return 0;
}
