#include <iostream>

using namespace std;

void insertionSort(int arr[], int n);
void printArray(int arr[], int n);

int main()
{
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<"Insertion Sort"<<endl;
    cout<<"Antes de ordenar: "<<endl;
    printArray(arr,n);

    cout<<endl<<"Despues de ordenar: "<<endl;
    insertionSort(arr,n);
    printArray(arr,n);


    return 0;
}


void insertionSort(int arr[], int n){

    int i, key, j;
    for( i=1; i < n ; i++){
        key = arr[i];
        j= i-1; 
        
        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j = j - 1; 
        }
        arr[j+1]= key; 
    }


}

void printArray(int arr[], int n){
     for(int i=0; i < n; i++){
        cout<<arr[i]<<" ";
     }
}