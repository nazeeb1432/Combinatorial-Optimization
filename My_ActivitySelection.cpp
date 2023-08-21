#include<bits/stdc++.h>
using namespace std;

struct job{

    char jobid[20];
    int start_time;
    int finish_time;
    int compatibility;
    
}jobs[100],temp;

int numOfJobs;

void print(){
    for(int i=0;i<numOfJobs;i++){
        cout<<jobs[i].jobid<<" "<<jobs[i].start_time<<" "<<jobs[i].finish_time<<" "<<jobs[i].compatibility<<endl;
        }

}

void readInput(){

    cin>>numOfJobs;
    for(int i=0;i<numOfJobs;i++){
        cin>>jobs[i].jobid>>jobs[i].start_time>>jobs[i].finish_time;
        jobs[i].compatibility=1;        
    }

   print();
}

void sort(){
    for(int i=0;i<numOfJobs-1;i++)
    {
        for(int j=i+1;j<numOfJobs;j++)
        {
            if(jobs[i].finish_time>jobs[j].finish_time)
            {
                temp=jobs[i];
                jobs[i]=jobs[j];
                jobs[j]=temp;
            }
        }
    }
    
}



void iterative(){
    for(int i=0;i<numOfJobs;i++){
        if(jobs[i].compatibility ==1){
            for(int j=i+1;j<numOfJobs;j++){
                if(jobs[j].start_time<jobs[i].finish_time){
                    jobs[j].compatibility=0;
                }
            }
        }
    }
}

void recursive(int i){//here i is the starting job

    int m=i+1;
    while(m<=numOfJobs && jobs[m].start_time<jobs[i].finish_time){ 
        jobs[m].compatibility=0;
        m++;
    }

    if(m<=numOfJobs){
        recursive(m);
    }
    //else return;

}



int main(){

        freopen("Activity_input.txt", "r", stdin);
        readInput();
        fclose(stdin);

        cout<<"_________________________"<<endl;

        //now sort them in the basis of finish time.
        sort();

        print();

        cout<<"_________________________"<<endl;

        //iterative();

        recursive(0);

        //now print jara compatible
        for(int i=0;i<numOfJobs;i++){
            if(jobs[i].compatibility){
                cout<<jobs[i].jobid<<" "<<jobs[i].start_time<<" "<<jobs[i].finish_time<<" "<<jobs[i].compatibility<<endl;
            }
        }

        cout<<"_________________________"<<endl;








}