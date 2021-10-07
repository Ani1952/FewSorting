#include <bits/stdc++.h>

using namespace std;

void InsertionSort(int arr[],int n){
	
	int i,j,f;
	for(i=1;i<n;i++){
		f=arr[i];
		j=i-1;
		while(j>=0 && arr[j]<f){
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=f;
	}
	
	for(i=0;i<n;i++){
		cout<<arr[i]<<endl;
	}
}

int main(){

int n,x,arr[100];
	cout<<"Enter the size of the array"<<endl;
	cin>>n;
	cout<<"Enter the elements of the array"<<endl;
	for(int i=0;i<n;i++){
		cin>>x;
		arr[i]=x;
	}
	
	InsertionSort(arr,n);
return 0;
}

