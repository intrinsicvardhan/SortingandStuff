#include <iostream>
using namespace std;
#define start 0; 
void toh(int n, int start ,int mid,  int end) {
    
    if(n==0) 
        cout<<"transferring x0 to mid and subsequently in end tower\n"; 
    toh(n-1, int start, int mid, int end); 
    cout<<"transferring from "<<start<<" to "<<mid
    
}

int main() {
    toh(int n, 
    
}