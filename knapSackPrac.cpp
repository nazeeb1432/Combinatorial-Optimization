#include<bits/stdc++.h>
using namespace std;

double profit[7]={10,5,15,7,6,18,3};
double weight[7]={2,3,5,7,1,4,1};//constraint max weight 15
              //5 1.67 3 1 6 4.5 3


double max_profit=0.0;
double  max_weight=15;

double profit_by_weight[7];

int max(int size){
    int max=0;

    for(int i=0;i<size;i++){
        if(profit_by_weight[i]>profit_by_weight[max]) max=i;
    }

    return max;
}
int main(){


    for(int i=0;i<7;i++){
        profit_by_weight[i]=profit[i]/weight[i];
        cout<<profit_by_weight[i]<<endl;
    }
    // 5 1.67 3 1 6 4.5 3


    while(max_weight)
    {
        int objectIdx=max(7);//extract the maximum p/w value wala object

        if(weight[objectIdx]<=max_weight){

            // printf("max_weight1=%lf\n",max_weight);
            max_weight-=weight[objectIdx];   

            printf("max_wight=%lf\n",max_weight);

            max_profit+=profit[objectIdx];

            profit_by_weight[objectIdx]=-1;
        }
        else{
            max_profit+=max_weight*profit_by_weight[objectIdx];
            max_weight=0;
        }
    }

    cout<<"Max profit: "<<max_profit<<endl;





}