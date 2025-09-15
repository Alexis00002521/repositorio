#include <iostream>

using namespace std; 

void printArray(int arr[], int n){
     for(int i=0; i < n; i++){
        cout<<arr[i]<<" ";
     }
}

void mergeSort(){
    
}

int main(){

    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);  
    
    cout<<"Merge Sort"<<endl;
    cout<<"Antes de ordenar"<<endl;
    printArray(arr, n);

    // mergeSort(arr,n);

    cout<<endl<<"Despues de ordenar"<<endl;
    printArray(arr, n);

    return 0; 
}