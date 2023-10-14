/* 
 * Merge sorting
 *  Time Complexity: O(nlogn), we perform operation of n elements for logn times
 *  Auxiliary Space: O(n), we use an auxiliary array of size at most n to store the merged subarray
 */

#include<iostream>
using namespace std;

void printArray(int arr[], int size) {
    for (int i=0; i<size; i++) {
        cout<< arr[i] <<" ";
    }
    cout<<endl;
}

void merge(int arr[], int begin, int mid, int end) {
    int i = begin;
    int j = mid+1;
    int k = begin;

    int size = end - begin + 1;
    int b[size];
    while( i<=mid && j<= end) {
        if (arr[i] < arr[j]) {
            b[k] = arr[i];
            i++;
        } else {
            b[k] = arr[j];
            j++;
        }
        k++;
    }
    if (i>mid) {
        while(j<=end) {
            b[k] = arr[j];
            k++;
            j++;
        }
    }
    if (j>end) {
        while(i<=mid) {
            b[k] = arr[i];
            k++;
            i++;
        }
    }
    for(int k=begin; k<=end; k++) {
        arr[k] = b[k];
    }
}

void mergeSort(int arr[], int begin, int end) {
    if (begin >= end) {
        return;
    }
    int mid = (begin + end) / 2;
    mergeSort(arr, begin, mid);
    mergeSort(arr, mid+1, end);

    merge(arr, begin, mid, end);
}

int main() {
    int arr[] = {9,4,7,6,3,1,5};
    int arr_size = sizeof(arr)/sizeof(arr[0]);

    printArray(arr,arr_size);

    mergeSort(arr, 0, arr_size-1);

    printArray(arr,arr_size);

}
