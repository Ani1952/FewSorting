 #include <bits/stdc++.h>

using namespace std;

void swap(int *xp, int *yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[],int n){
	int i, j; 
	for (i = 1; i <n; i++){
		bool s=false;
		for (j = 0; j <n-i; j++){
			
			if(arr[j]>arr[j+1]){
				swap(&arr[j+1],&arr[j]);
				s=true;
			}
		}
		if(s==false) break;
	}
}
void printArray(int arr[], int size) 
{ 
    int i; 
    for (i = 0; i < size; i++) 
        cout << arr[i] << " "; 
    cout << endl; 
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
	bubbleSort(arr,n);

return 0;
}

