#include <iostream>

using namespace std; 

void printArray(int arr[], int n){
     for(int i=0; i < n; i++){
        cout<<arr[i]<<" ";
     }
}

void selectionSort(int arr[], int n){

    for( int i=0; i < n-1; i++){  
        int min_idx = i;
        
        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[min_idx]){

                min_idx = j;
            }

        }
        swap(arr[min_idx], arr[i]);

    }
}

int main(){

     int arr[] = {12, 11, 13, 5, 6};
     int n = sizeof(arr)/sizeof(arr[0]);

    cout<<"Selection Sort"<<endl;
    cout<<"Antes de ordenar: "<<endl;
    printArray(arr,n);

    cout<<endl<<"Despues de ordenar: "<<endl;
    selectionSort(arr,n);
    printArray(arr,n);    

    return 0;
}