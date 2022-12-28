#include <iostream>
using namespace std;

//here m is the size of the array1 and n is the size of the array2
void merge(int arr1[], int arr2[], int m, int n) { //merging two sorted arrays 
    int i{}, j{} , k{};
    int arr3[m+n] {};
    while(i<m&&j<n) {
        if(arr1[i]<arr2[j]) {
            arr3[k] = arr1[i]; 
            k++; 
            i++;
        }
        else {
            arr3[k] = arr2[j];
            j++; 
            k++;
        }
    }
    for(;i<m; ++i) 
        arr3[k++] = arr1[i]; 
    for(;j<n ;++j) 
        arr3[k++] = arr2[j];
        
    cout<<"the merged array is\n";
        
    for(int l = 0; l<m+n; ++l) 
        cout<<arr3[l]<<" ";
}

void merge(int arr[], int l, int h, int n) {
    int mid = (l+h)/2;
    int i =l, j = mid+1;
    int arr2[n] {}, k{};
    while(i<=mid&&j<=h) {
        if(arr[i]<arr[j])
            arr2[k++] = arr[i++]; 
        else
            arr2[k++] = arr[j++];
    }
    for(; i<= mid;i++)
        arr2[k++] = arr[i];
    for(;j<=h;j++)
        arr2[k++] = arr[j];
        
    for(int i =0; i<n; ++i) {
        arr[i] = arr2[i];
    }
}

int main() {
    int arr1[] {1,2,3,4,5,6}; 
    int arr2[] {7,8,9,10,11};
    int m = sizeof(arr1)/sizeof(arr1[0]);
    int n = sizeof(arr2)/sizeof(arr2[0]);
    merge(arr2, arr1, m, n);
}