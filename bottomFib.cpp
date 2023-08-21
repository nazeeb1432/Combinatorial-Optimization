#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll fibNUM[100];

ll fib(ll n){
    for(ll i=0;i<=n;i++){
        if(i<=1){
            fibNUM[i]=i;

        }
        else{
            fibNUM[i]=fibNUM[i-1]+fibNUM[i-2];
        }
    }

    return fibNUM[n];
}

int main(){

    ll n;
    cin>>n;

    cout<<fib(n)<<endl;

}