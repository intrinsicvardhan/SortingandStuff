#include <iostream>
using namespace std;
//count sort uses an extra array to count the number of times a number is present
int find_max(int arr[], int n) {
    int m = arr[0];
    for(int i = 1; i<n; i++) {
        if(arr[i]>m) 
            m = arr[i];
    }
    return m;
}

void count_sort(int arr[], int n) {
    int max = find_max(arr, n); 
    int count[max+1]; 
    for(int i =0; i<max+1; i++) {
        count[i] = 0;
    }
    
    for(int i =0; i<n ;i++) {
        count[arr[i]]++;
    }
    
    int j{};
    for(int i=0 ;i<max+1; i++) {
        while(count[i]>0&&j<n) {
            arr[j] = i;
            j++;
            count[i]--;
        }
    }
}

int main() {
    int arr[] = {6,2,3,3,1,9,10,8,5,5}; //O(m+k) where k is the maximum number present in the original array
    int n = sizeof(arr)/sizeof(arr[0]);
    count_sort(arr, n);
    for(int i = 0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
    return 0;
}