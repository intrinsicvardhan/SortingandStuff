//using horner's rule to calculate sinx
#include <bits/stdc++.h>

using namespace std;

#define PI 3.14159

double t_sin(double x, int n) {
    static double s{1};
        if(n==1) 
            return s*=x;
            
        else 
            s = 1-s*((x*x)/((2*n-1)*(2*n-2)));            
    return t_sin(x,n-1);
}



double t_cos(double x, int n) {
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout<<t_sin(PI,100);
    cout<<"\n"<<t_sin(PI/2,100)<<"\n"<<t_sin(PI/4,100);
}