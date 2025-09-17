#include <iostream>

using namespace std;

void printArray(int arr[], int n){
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}

void mergeWithBuffer(int arr[], int left, int mid, int right, int temp[]){
    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (int t = left; t <= right; t++) {
        arr[t] = temp[t];
    }
}

void mergeSortWithBuffer(int arr[], int left, int right, int temp[]){
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSortWithBuffer(arr, left, mid, temp);
    mergeSortWithBuffer(arr, mid + 1, right, temp);
    mergeWithBuffer(arr, left, mid, right, temp);
}

void mergeSort(int arr[], int n){
    int* temp = new int[n];
    mergeSortWithBuffer(arr, 0, n - 1, temp);
    delete[] temp;
}

int main(){
    int arr[] = {38, 27, 43, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Merge Sort" << endl;
    cout << "Antes de ordenar" << endl;
    printArray(arr, n);

    mergeSort(arr, n);

    cout << endl << "Despues de ordenar" << endl;
    printArray(arr, n);

    return 0;
}