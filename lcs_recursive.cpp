#include<bits/stdc++.h>
using namespace std;
char str1[100],str2[100];
string s;

int dp[100];
int lcs_store[100][100];

int LCS(int i,int j){
    if(lcs_store[i][j]!=-1) return lcs_store[i][j];

    if(str1[i]=='\0' || str2[j]=='\0') return 0;
    else if(str1[i]==str2[j]){
        if(dp[i]==-1) dp[i]=i;
           
        return lcs_store[i][j]=1+LCS(i+1,j+1);
    }
    else{
        return lcs_store[i][j]=max(LCS(i+1,j),LCS(i,j+1));
    }
}

int main(){

   
   cout<<"Enter first string:";
   cin>>str1;
   cout<<"Enter second string:";
   cin>>str2;

   memset(dp,-1,sizeof(dp));
   memset(lcs_store,-1,sizeof(lcs_store));

   int i=strlen(str1);
   int j=strlen(str2);

    cout<<"Longest increasing subsequence:"<<LCS(0,0);
    cout<<endl;

    for(int i=0;i<100;i++){
        if (dp[i]!=-1){
            cout<<str1[dp[i]];
        }
    };
    



}