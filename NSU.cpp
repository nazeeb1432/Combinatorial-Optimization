#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll nsuNUM[100];

ll nsu(ll n){
    for(ll i=0;i<=n;i++){

        if(i<=2){
            nsuNUM[i]=i;

        }
        else{
            nsuNUM[i]=nsuNUM[i-1]+nsuNUM[i-2]+nsuNUM[i-3];
        }
    }

    return nsuNUM[n];
}

int main(){

    ll n;
    cin>>n;

    cout<<nsu(n)<<endl;

}