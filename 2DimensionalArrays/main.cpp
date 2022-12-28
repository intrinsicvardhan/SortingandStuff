#include <iostream>
using namespace std;

#define r 3 
#define c 3 

int arr[r][c] = {};

void display(int arr[][c]) {
    for(int i =0; i<r; ++i) {
        for(int j =0; j<c; ++j) {
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
}

//for transpose we make ij elements equal to ji
void transpose(int arr[][c]) {
    int temp[][c] = {};
    for(int i =0; i<r; ++i) {
        for(int j=0; j<r; ++j) {
            temp[i][j] = arr[i][j];
    }
}

for(int i =0; i<r; ++i) {
        for(int j=0; j<r; ++j) {
            arr[i][j] = temp[j][i];
    }
}
}

void diagonalise(int arr[][c]) {//diagonal elements are non zero!
    for(int i = 0; i<r;++i) {
        for(int j = 0; j<c; ++j) {
            if(i!=j)
                arr[i][j] =0;
        }
    }
}

void tridiag(int arr[][c]) {
    for(int i =0; i<r; ++i) {
        for(int j =0; j<c; ++j) {
            if(abs(i-j)>1)
                arr[i][j] = 0;
        }
    }
}

void symmetric(int arr[][c]) {
    for(int i =0; i<r; ++i) {
        for(int j = 0;j<i; ++j) { 
            arr[j][i] = arr[i][j];
        }
    }
}


void upper_triang(int arr[][c]) {
    for(int i =0; i<r; ++i) {
        for(int j =0;j<c; ++j) {
            if(i<=j) 
                arr[i][j]=0;
        }
    }
}

void lower_triang(int arr[][c]) {
    for(int i =0; i<r; ++i) {
        for(int j =0;j<c; ++j) {
            if(i>=j) 
                arr[i][j]=0;
        }
    }
}


//a saddle point is a number which is larger than every number in its column 
// and smaller than every number in its row 
int saddle_point(int arr[][c]) {
    int m{};
    int s{};
    bool flag{};
    for(int i =0; i<r; ++i) {
        m = arr[i][0]; 
        for(int j = 0; j<c; ++j) {
            if(arr[i][j]<m){
                m= arr[i][j];
                s = j;
            }
        }
        for(int k =0; k<r; ++k) {
            if(arr[k][s]>m) {
                flag = 0;
                break;
            }
            else
                flag = 1;
        }
        if(flag) 
            return m;
    }
    
    return -1;
}

void spiral(int arr[][c], int m, int n) {
    
    m = r;
    n = c; 
    for(int i =0; i<n; ++i) {
        cout<<arr[
    }
    
    
}

int main() {
    
    cout<<"input the elements of the array\n";
    for(int i =0; i<r; ++i) {
        for(int j =0; j<c; ++j) {
            cin>>arr[i][j];
        }
    }
    
    display(arr);
    spiral(arr,3,3);
    
    
}