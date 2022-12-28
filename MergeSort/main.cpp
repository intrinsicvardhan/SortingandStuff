#include <iostream>
#include <merge.h>
using namespace std;

//merging two sorted arrays
//compare first two elements of the array 
//fill the new array with the smaller element and keep doing it
void merge_sort(int arr[] , int n) { //iterative version is wrong
    int p{}, i{}, l{}, mid{}, h{};
    for(p = 2; p<=n; p*=2) {
        for(i = 0; i+p-1<n; i+=p) {
            l =i;
            h = i+p-1;
            mid = (l+h)/2;
            merge(arr,l,mid,h);
        }
    }
    if(p/2<n) 
        merge(arr,0,p/2,n-1);
}

void merge_sort(int arr[], int l, int h) { //recursive version works
    int mid{} ;
    if(l<h) {
        mid = (l+h)/2; 
        merge_sort(arr, l, mid); 
        merge_sort(arr, mid+1, h); 
        merge(arr, l, mid, h); 
    }
}

int main() {
    int arr[] = {2,1,21,30,23,31,22,11,9,3,4,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    merge_sort(arr, 0,n-1);
    cout<<"the sorted array is \n";
    for(int i =0; i<n; i++) 
        cout<<arr[i]<<" ";
}