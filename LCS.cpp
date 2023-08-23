#include<bits/stdc++.h>
using namespace std;
#define size 100

#define DIAGONAL_ARROW 1
#define UP_ARROW 2
#define LEFT_ARROW 3

int c[size][size];//CAONTAINS THE LCS NUMBER
int b[size][size];//CONTAINS THE ARROWS

char x[20];
char y[20];

int LCS_LENGTH(char x[],char y[],int m,int n){
    // int i,j;
    for(int i=0;i<=m;i++){
        c[i][0]=0;
    }
    for( int j=0;j<=n;j++){
        c[0][j]=0;
    }
    for(int i=1;i<=m;i++){
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


    return c[m][n];
}

void print_lcs(char x[],int i,int j){
    if (i==0 || j==0) return;

    if(b[i][j]==DIAGONAL_ARROW){
        print_lcs(x,i-1,j-1);
        cout<<x[i];
    }
    else if(b[i][j]==UP_ARROW){
        print_lcs(x,i-1,j);
    }
    else{
        print_lcs(x,i,j-1);
    }

}

int main(){
    
    

    cout<<"Enter first string:";
    cin>>&x[1];
    cout<<"Enter second string:";//bdcaba
    cin>>&y[1];

    int m=strlen(&x[1]);
    // printf("%d",m);
    int n=strlen(&y[1]);
    // printf("%d",n);


    cout<<"LongestCommonSubsequence:"<<LCS_LENGTH(x,y,m,n)<<endl;

    cout<<"Longest common string:"<<endl;

    print_lcs(x,m,n);



    return 0;
    
}