#include <bits/stdc++.h>
using namespace std;

void swap(int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int arr[], int left, int right){
    int pivot = arr[right];
    int i = left-1;

    for (int j = left; j < right; j++){
        if(arr[j] < pivot){
            i++;
            swap(arr, i, j);
        }
    }

    swap(arr, i+1, right);
    return i+1;
}

void quickSort(int arr[], int left, int right){
    if ( left < right) {
        int pi = partition(arr, left, right);
        quickSort(arr, left, pi-1);
        quickSort(arr, pi+1, right);
    }
}

int main(){

    int arr[5] = {5,4,3,2,1};
    quickSort(arr, 0, 4);
    for (int i = 0; i < 5; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";

    return 0;
}