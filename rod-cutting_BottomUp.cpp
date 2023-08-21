#include<bits/stdc++.h>
using namespace std;



int bottom_up_cut_rod(int p[],int n){
    int r[n];
    r[0]=0;

    for(int j=1;j<=n;j++){//j indicates the rod length
        int q=-INT_MAX;
        for(int i=1;i<=j;i++){
            q=max(q,p[i]+r[j-i]);
        }
        r[j]=q;//r[j] array indicates j length er rod er jonno max revenue
    }

    return r[n];
}

int main(){

    // int size=sizeof(p)/sizeof(p[0]);

    int p[]={0,1,5,8,9,10,17,17,20,24,30};

    int n;
    cout<<"Enter rod length:";
    cin>>n;

    int max_revenue=bottom_up_cut_rod(p,n);

    cout<<"Max revenue is:"<<max_revenue<<endl;



}