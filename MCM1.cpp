#include<bits/stdc++.h>
using namespace std;


int f(int i,int j,vector<int> &arr, vector<vector<int>> &dp){

    if(i==j) return 0;

    int mini=1e9;

    if(dp[i][j]!=-1) return dp[i][j];

    for(int k=i;k<j;k++){
        int steps=arr[i-1]*arr[k]*arr[j]+f(i,k,arr,dp)+f(k+1,j,arr,dp);

        if(steps<mini) mini=steps;
    }

    return dp[i][j]=mini;


}


int matrix_chain_multiplication(vector<int> &arr, int N){
    //for memoization
    vector<vector<int>> dp(N,vector<int>(N,-1));//row->N,column N,initialized with -1
    return f(1,N-1,arr,dp);
}

int main(){
    vector<int> arr={10,20,30,40,50};

   int answer= matrix_chain_multiplication(arr,arr.size());

   cout<<"Minimum operations: "<< answer<<endl;


}