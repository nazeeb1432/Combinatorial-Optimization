#include<bits/stdc++.h>
using namespace std;

#define size 100
int c[size][size];

int combination(int n,int r){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=min(i,r);j++){
            if(j==1) c[i][j]=i;
            else if(j==i || j==0) c[i][j]=1;
            else{
                c[i][j]=c[i-1][j-1]+c[i-1][j];
            }

        }
    }

    return c[n][r];
}

int main(){

    int n,r;
    cin>>n>>r;

    cout<<combination(n,r)<<endl;

}