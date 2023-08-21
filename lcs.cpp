#include<bits/stdc++.h>
using namespace std;
#define mx 100

#define DIAGONAL_ARROW 1
#define UP_ARROW 2
#define LEFT_ARROW 3

int c[mx][mx];//CAONTAINS THE LCS NUMBER
int b[mx][mx];//CONTAINS THE ARROWS


int LCS_LENGTH(string x,string y,int m,int n){
    int i,j;
    for( i=0;i<=m;i++){
        c[i][0]=0;
    }
    for( j=0;j<=n;j++){
        c[0][j]=0;
    }
    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){

            if(x[i-1]==y[j-1]){
                c[i][j]=1+c[i-1][j-1];
                b[i][j]=DIAGONAL_ARROW;
            }
            else if(c[i-1][j]>= c[i][j-1]){
                c[i][j]=c[i-1][j];
                b[i][j]=UP_ARROW;
            }
            else{
                c[i][j]=c[i][j-1];
                b[i][j]=LEFT_ARROW;
            }

        }
    }

    return c[m][n];
}

void print_lcs(string x,int i,int j){
    if (i==0 || j==0) return;

    if(b[i][j]==DIAGONAL_ARROW){
        print_lcs(x,i-1,j-1);
        cout<<x[i-1];
    }
    else if(b[i][j]==UP_ARROW){
        print_lcs(x,i-1,j);
    }
    else{
        print_lcs(x,i,j-1);
    }

}

int main(){

    string x,y;
    cout<<"Enter first string:";//abcbdab
    cin>>x;
    cout<<"Enter second string:";//bdcaba
    cin>>y;

    int m=x.size();
    int n=y.size();

    cout<<"LongestCommonSubsequence:"<<LCS_LENGTH(x,y,m,n)<<endl;

    cout<<"Longest common string:"<<endl;

    print_lcs(x,m,n);





}
