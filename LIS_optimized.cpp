#include<bits/stdc++.h>
using namespace std;

#define max 100

int L[max],L_prime[max],prv[max];

void LIS_Fast_Dp(int a[],int n){
    L[0]=-INT_MAX;
    L_prime[0]=-1;
    prv[0]=-1;
    int index=0;

    for(int i=1;i<=n;i++){
        if(L[index]<a[i]){
            L[++index]=a[i];
            L_prime[index]=i;
            prv[i]=L_prime[index-1];
        }
        else{

        }
    }
}

int binarySearch(int arr[], int l, int r, int x)
{
    while (l <= r) {
        int m = l + (r - l) / 2;
 
       
        if (arr[m] == x)
            return m;
 
        
        if (arr[m] < x)
            l = m + 1;
 
        
        else
            r = m - 1;
    }
 
}


int main(){

    int n,arr[max];

    cout<<"How many numbers?:";
    cin>>n;
    cout<<"Enter your sequence:";

    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }

    LIS_Fast_Dp(arr,n);


}