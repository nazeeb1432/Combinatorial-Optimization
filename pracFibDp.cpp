#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll fibNUM[100];

ll  fib(ll n){
    if(n<=1){
        fibNUM[n]=n;
        return fibNUM[n];
    }
    if(fibNUM[n]<0){

        fibNUM[n]=fib(n-1)+fib(n-2);
    }
    return fibNUM[n];
}

int main(){

    for(int i=0;i<100;i++){
        fibNUM[i] =-1;
    }
    ll n;

    cout<<"Enter the value of n:";
    cin>>n;
    cout<<"nth fib number is "<<fib(n)<<endl;



}