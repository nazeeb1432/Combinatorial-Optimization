#include<bits/stdc++.h>
using namespace std;

#define size 100
int c[size][size];


int combination(int n,int r){

    if(c[n][r]!=-1){
        return c[n][r];//jaate double calcuate na kori
    }
    if(r==1) c[n][r]=n;
    else if(r==n || r==0){
        c[n][r]=1;
    }
    else{
        c[n][r]=combination(n-1,r-1)+combination(n-1,r);
    }

    return c[n][r];


}

int main(){

    int n,r;
    cin>>n>>r;

    for(int i=0;i<=n;i++){
        for(int j=0;j<=r;j++){
            c[i][j]=-1;
        }
    }

    cout<<combination(n,r)<<endl;

}