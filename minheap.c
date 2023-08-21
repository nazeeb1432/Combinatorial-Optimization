#include<stdio.h>


void heapify(int cbt[],int i);
void insert(int cbt[],int newNode);
void doInsert(int cbt[],int index);
void delete(int cbt[], int deleteNode);
int extractRoot(int cbt[]);
void swap(int *a,int *b);
void print(int cbt[]);

int size=0;

int main(int argc,char *argv[])
{

    int cbt[10]={3,9,2,7,4,5}; //cbt-> complete binary tree
    int ins,del;
    for(int i=0;i<10;i++){
        if(cbt[i]!=0) size++;
    }
    
    for(int i=(size/2)-1;i>=0;i--){
        heapify(cbt,i);
    }
    print(cbt);

    printf("Enter node to insert:");
    scanf("%d",&ins);
    insert(cbt,ins);
    print(cbt);
    printf("Enter node to delete:");
    scanf("%d",&del);
    delete(cbt,del);
    print(cbt);

    int root=extractRoot(cbt);
    printf("Root:%d\n",root);

    print(cbt);

    return 0;
}
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;

}
void heapify(int cbt[],int i){
    int l,r,smallest;
    smallest=i;
    l=2*i+1;
    r=2*i+2;

    if(l<size && cbt[l]<cbt[smallest]) smallest=l;
    if(r<size && cbt[r]<cbt[smallest]) smallest=r;

    if(smallest!=i){
        swap(&cbt[smallest],&cbt[i]);
        heapify(cbt,smallest);
    }
    
}
void insert(int *cbt,int newNode){
    if(size==0){
        cbt[0]=newNode;
        size++;
    }else{
        cbt[size]=newNode;
        doInsert(cbt,size);
        size++;
    }
}
void doInsert(int *cbt,int index){
    int parent=(index-1)/2;
    if(cbt[parent] > cbt[index]){
        swap(&cbt[parent],&cbt[index]);
        doInsert(cbt,parent);
    }
}
void delete(int cbt[], int deleteNode) {
    int i;
    for (i = 0; i < size; i++) {
        if (deleteNode == cbt[i])
            break;
    }
    if (i == size) {
        printf("Node not found in the heap.\n");
        return;
    }

    swap(&cbt[i], &cbt[size - 1]);
    size--;

    heapify(cbt, i);
}
int extractRoot(int cbt[]){
    int x=cbt[0];
    swap(&cbt[0],&cbt[size-1]);
    size--;
    heapify(cbt,0);

    return x;
}
void print(int cbt[]){
    for(int i=0;i<size;i++){
        printf("%d ",cbt[i]);
    }
    printf("\n");
}