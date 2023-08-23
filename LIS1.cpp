#include<bits/stdc++.h>
using namespace std;

#define max 100 
#define size 100

#define DIAGONAL_ARROW 1
#define UP_ARROW 2
#define LEFT_ARROW 3

int c[size][size];//CAONTAINS THE LCS NUMBER
int b[size][size];//CONTAINS THE ARROWS

int x[50];
int y[50];


void LIS(int x[],int i,int j){
    if (i==0 || j==0) return;

    if(b[i][j]==DIAGONAL_ARROW){
        LIS(x,i-1,j-1);
        cout<<x[i]<<" ";
    }
    else if(b[i][j]==UP_ARROW){
        LIS(x,i-1,j);
    }
    else{
        LIS(x,i,j-1);
    }
}

void LCS(int x[],int y[],int n){
     for(int i=0;i<=n;i++){
        c[i][0]=0;
    }
    for( int j=0;j<=n;j++){
        c[0][j]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){

            if(x[i]==y[j]){
                c[i][j]=1+c[i-1][j-1];
                b[i][j]=DIAGONAL_ARROW;
            }
            else{
                 if(c[i-1][j]>= c[i][j-1]){
                c[i][j]=c[i-1][j];
                b[i][j]=UP_ARROW;
                }
                else{
                    c[i][j]=c[i][j-1];
                    b[i][j]=LEFT_ARROW;
                }
            }
            
        }
    }

    LIS(x,n,n);
    cout<<endl;

}

int main(){
   int n,arr[max],sorted_arr[max];
     
    cout<<"How many numbers?:";
    cin>>n;
    cout<<"Enter your sequence:";

    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }

    for(int i=1;i<=n;i++){
        sorted_arr[i]=arr[i];
    }

    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            if (sorted_arr[i]>sorted_arr[j]){
                int temp=sorted_arr[i];
                sorted_arr[i]=sorted_arr[j];
                sorted_arr[j]=temp;
            }
        }
    }

    LCS(arr,sorted_arr,n);

}