#include <iostream>

using namespace std; 

void printArray(int arr[], int n){
     for(int i=0; i < n; i++){
        cout<<arr[i]<<" ";
     }
}

void bubbleSort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        for(int j=0 ; j < n-1-i; j++){
            
            if(arr[j] > arr[j+1]){  
            swap(arr[j], arr[j+1]);
            }

        }
         
    }

}

int main(){
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<"Bubble Sort"<<endl;
    cout<<"Antes de ordenar: "<< endl;
    printArray(arr, n);

    bubbleSort(arr,n);
    cout<<endl<<"Despues de ordenar: "<< endl;
    printArray(arr, n);
    return 0;
}


