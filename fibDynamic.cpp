#include<bits/stdc++.h>
using namespace std;

long int fibNum[100];

long int fib(int n){
    
    if(n<=1){
        fibNum[n]=n;
        return fibNum[n];
    }

    if(fibNum[n]<0){
        fibNum[n]=fib(n-1)+fib(n-2);

    }

    return fibNum[n];
}

int main(){

    long int n;
    cin>>n;

    for(int i=0;i<100;i++){
        fibNum[i]=-1;
    }

    cout<<fib(n)<<endl;
    

    return 0;
}