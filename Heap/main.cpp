#include <iostream>

using namespace std; 
#define size 100

class Heap {
public:
    int arr[size];
    Heap() {
        for(int i =0; i<size; i++) {
            arr[i] = -1; 
        }
    }
    int length= 0; 
    void insert(int x) { //O(logn) time is the complexity 
       length++; 
       arr[length-1] = x; 
       int i {length-1}; 
        while(i>0) {
            if(i%2==0&&arr[i]>arr[i/2-1])
                swap(arr[i], arr[i/2-1]); 
            else if(i%2!=0&&arr[i]>arr[i/2]) 
                swap(arr[i],arr[i/2]); 
            i/=2;
    }
}     
        void inorder(int x) {
            if(arr[x]==-1) 
                return; 
            inorder(2*x+1); 
            cout<<arr[x]<<" "; 
            inorder(2*x+2);
        }
        void Delete() {
            swap(arr[0],arr[length-1]); 
            int i {0};
            arr[length-1] = -1; 
            length--; 
            while(arr[i]!=-1&& arr[2*i+1]!=-1&&arr[i]<arr[2*i+1]) {
                swap(arr[i],arr[2*i+1]); 
                if(arr[2*i+1]>arr[2*i+2])
                    swap(arr[2*i+1],arr[2*i+2]);
                i =2*i+1;
            }
        }
};

int main() {
    Heap h;
    h.insert(15); 
    h.insert(11); 
    h.insert(5); 
    h.insert(9); 
    h.insert(7); 
    h.insert(6); 
    h.Delete();
    h.inorder(0); 
    return 0; 
}