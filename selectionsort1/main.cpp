#include <iostream>
#include <valarray>
using namespace std;
//take out the minimum elemeent of the subarray and put it on the first place of the sub array
void sort(int arr[], int n) {
  
    for(int i =0 ; i<n; ++i) {
       int minindex = i;
       int min = arr[i];
        for(int j =i+1; j<n; ++j) {
            if(min>arr[j]) {
                minindex = j;
                min = arr[j];
            }
        }
           swap(arr[i],arr[minindex]);
    }
}

int main() {
    int arr[]  {7,2,101011012,11,5,9,1010101,100}; 
    int n = sizeof(arr)/sizeof(arr[0]);
    sort(arr, n);
    for(int i = 0; i <n; ++i) {
        cout<<arr[i]<<" ";
    }
    return 0;
}