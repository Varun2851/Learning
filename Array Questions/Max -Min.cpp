#include<iostream>
using namespace std;
int main(){


         int arr[] = {1,3,4,1};
         int n = 4;
         int sum = 0;
 
         int max = arr[0];
         int min = arr[0];
         
         for(int i =1; i<n; i++ ){
         	if(arr[i]>max){
         		max = arr[i];
			}
			if(arr[i]<min){
				min = arr[i];
			}
         	
		 }
		  sum = max+min;
		  cout<<sum<<endl;
	      return 0;
}
