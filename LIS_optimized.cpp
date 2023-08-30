#include<bits/stdc++.h>
using namespace std;

#define max 100
int pos;

int L[max],L_prime[max],prv[max];

void LIS_Fast_Dp(int a[],int n){
    L[0]=-INT_MAX;
    L_prime[0]=-1;
    prv[0]=-1;
    int index=0;

    for(int i=1;i<=n;i++){
        if(L[index]<=a[i]){
            L[++index]=a[i];
            L_prime[index]=i;
            prv[i]=L_prime[index-1];
        }
        else{
            int s=0,h=index;
            while(s<h){
                int mid=(s+h)/2;
                if(L[mid]<a[i]) s=mid+1;
                else h=mid;
            }
            L[s]=a[i];
            L_prime[s]=i;
            prv[i]=L_prime[s-1];
                                                                                                                                       
        }
    }
    pos=index;
    
}

void printLIS(int arr[],int i){
    if(i==-1) return;
    printLIS(arr,prv[i]);
    cout<<arr[i]<<" ";
}


int main(){

    int n,i,arr[max];

    cout<<"How many numbers?:";
    cin>>n;
    cout<<"Enter your sequence:";

    arr[0]=0;

    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }

    LIS_Fast_Dp(arr,n);
    cout<<"Length of LIS:"<<pos<<endl;

    cout<<"LIS: ";
    
    for(i=0;i<=n;i++){
        if(arr[i]==L[pos]) break;
    }

    printLIS(arr,pos-1);
    cout<<L[pos];



}