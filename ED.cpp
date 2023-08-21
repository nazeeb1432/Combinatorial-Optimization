#include<bits/stdc++.h>
using namespace std;
#define SIZE 100

#define DIAG_ARROW 1//insert
#define UP_ARROW 2//delete
#define LEFT_ARROW 3//insert
#define DOUBLE_DIAG_ARROW 4//no change,copy c[i-1][j-1] i.e diagonal to c[i][j]

int c[SIZE][SIZE];
int op[SIZE][SIZE];

int main(){

    char x[20];//="heater";
    char y[20];//="speak";

    cout<<"Enter string x:";
    cin>>&x[1];//start reading from index 1
    cout<<"Enter string y:";
    cin>>&y[1];


    int l1=strlen(x);
    int l2=strlen(y);

    

    for(int i=1;i<=l1;i++){
        c[i][0]=i;
        op[i][0]=UP_ARROW;
    }
    for(int j=1;j<=l2;j++){
        c[0][j]=j;
        op[0][j]=LEFT_ARROW;
    }

    for(int i=1;i<=l1;i++){
        for(int j=1;j<=l2;j++){
            int p=c[i-1][j-1];
            int q=c[i-1][j];
            int r=c[i][j-1];

            if(x[i]!=y[j]){

                int minimum=min(p,min(q,r));
                c[i][j]=minimum+1;
                
                    if(minimum==c[i-1][j-1]){
                        op[i][j]=DIAG_ARROW;
                    }
                    if(minimum==c[i-1][j]){
                        op[i][j]=UP_ARROW;
                    }
                    if(minimum==c[i][j-1]){
                        op[i][j]=LEFT_ARROW;
                    }
                
            }
            else{
                c[i][j]=c[i-1][j-1];
                op[i][j]=DOUBLE_DIAG_ARROW;
            }

        }

    }

    cout<<"ED:"<<c[l1][l2]<<endl;

    for(int i=0;i<=l1;i++){
        for(int j=0;j<=l2;j++){
            cout<<c[i][j]<<","<<op[i][j]<<"  ";
        }
        cout<<endl;
    }

    

    return 0;
}