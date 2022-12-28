#include <iostream>
#include <valarray>
using namespace std;

void max_heapify(int arr[], int n, int i) { //O(n) complexity
    int largest = i;
    int l = 2*i+1;
    int r = 2*i+2;
    if(l<n && arr[largest]<arr[l]) 
        largest = l; 
    if(l<n&& arr[largest]<arr[r]) 
        largest = r; 
    
    if(largest!=i)  {
        swap(arr[i],arr[largest]); 
        max_heapify(arr,n,largest);   
    }
}

void heap_sort(int arr[], int n) {
    for(int i =n/2-1;i>=0; i--) 
        max_heapify(arr,n, i); 
        
    for(int i =n-1; i>0; i--) { //heapify is of order O(n)
        swap(arr[i],arr[0]) ;
        max_heapify(arr,i,0);
    }
}

int main() {
    int arr[] = {4,3,10,23,11,22,17,1,7}; 
    int n = sizeof(arr)/sizeof(arr[0]);
    heap_sort(arr,n);
    for(int i =0;i<n; i++) {
        cout<<arr[i]<<" ";
    }
    return 0; 
}