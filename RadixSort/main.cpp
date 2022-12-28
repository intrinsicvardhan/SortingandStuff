#include <iostream>
#include <radix.h>
using namespace std;


void radix_sort(int arr[], int n) {
    int x = passes(find_max(arr,n));
    int div {1};
    node **p = new node* [10];
    initialiseBins(p,10); 
    while(x) {
        for(int i =0; i<n; i++) {
            int idx = (arr[i]/div)%10; 
            insertBin(p, idx, arr[i]);
        }
        int j{};
        for(int i =0; i<10; i++) {
            while(p[i]) {
                arr[j] = deleteBin(p,i);
                j++;
            }
        }
        div*=10;
        x--;
    }
}

int main() {
    int arr[] = {2,200,10,40,748,62,11,348}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    radix_sort(arr,n); 
    for(int i =0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
    return 0;
}