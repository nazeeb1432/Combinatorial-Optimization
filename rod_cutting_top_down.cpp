#include<bits/stdc++.h>
using namespace std;

int q=-INT_MAX;

int memoized_cut_rod_aux(int p[],int n,int r[]){
    if (r[n]>=0){
        return r[n];
    }

    if(n==0){
       q=0;
    }
    else q=-INT_MAX;
    
    for(int i=1;i<=n;i++){
        q=max(q,p[i]+memoized_cut_rod_aux(p,n-i,r));       
    }

    r[n]=q;

    return r[n];
}



int memoized_cut_rod(int p[],int n){
    int r[n];

    for(int i=0;i<=n;i++){
        r[i]=-INT_MAX;
    }

    return memoized_cut_rod_aux(p,n,r);
}




int main(){

    int p[]={0,1,5,8,9,10,17,17,20,24,30};


    int n;
    cout<<"Enter rod length:";
    cin>>n;

    int max_revenue=memoized_cut_rod(p,n);

    cout<<"Max-Revenue is: "<<max_revenue<<endl;
}