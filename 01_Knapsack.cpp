#include<bits/stdc++.h>
using namespace std;
#define MAX 10000
int wt[MAX],val[MAX];

long long dp[MAX][MAX];

long long func(int ind,int wt_left){
    if(wt_left ==0) return 0;
    if(ind<0) return 0;
    if(dp[ind][wt_left]!=-1) return dp[ind][wt_left];
    //Don't choose item at index
    long long ans=func(ind-1,wt_left);
    //choose item at index
    if(wt_left-wt[ind]>=0){

      ans=max(ans,func(ind-1,wt_left-wt[ind])+val[ind]);
    }
    return dp[ind][wt_left]=ans;
}

int main(){

    //initialize dp 2D array with -1
    memset(dp,-1,sizeof(dp));


    int n,w;
    cin>>n>>w;

    for(int i=0;i<n;++i){
        cin>>wt[i]>>val[i];
    }

    cout<<func(n-1,w);

}