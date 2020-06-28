#include<stdio.h>
#include<stdlib.h>
struct Queue{
    int data;
    struct Queue *next;
}*front=NULL,*rear=NULL;
void Enqueue(struct Queue **head,struct Queue **tail,int data){
    struct Queue *node=(struct Queue *)malloc(sizeof(struct Queue));
    node->data=data;
    node->next=NULL;
    if(*head==NULL && *tail==NULL)
        *head=*tail=node;
    else{
        struct Queue *p=*tail;
        p->next=node;
        *tail=node;
    }
}
int Dequeue(struct Queue **head,struct Queue **tail){
    int temp;
    struct Queue *p=*head;
    *head=p->next;
    if(*head==NULL)
        *tail=NULL;
    temp=p->data;
    free(p);
    return temp;
}
int isEmptyQueue(struct Queue **head,struct Queue **tail){
    if(*head==NULL && *tail==NULL)
        return 1;
    return 0;
}
void BFS(int AM[8][8],struct Queue **head,struct Queue **tail,int visited[],int u){
    int v;
    printf("%d\t",u);
    visited[u]=1;
    Enqueue(head,tail,u);
    while(!isEmptyQueue(head,tail)){
        u=Dequeue(head,tail);
        for(v=1;v<8;v+=1){
            if(AM[u][v]==1 && visited[v]==0){
                printf("%d\t",v);
                visited[v]=1;
                Enqueue(head,tail,v);
            }
        }
    }
}
int main(){
    int AM[8][8]={{0,0,0,0,0,0,0,0},
                 {0,0,1,1,1,0,0,0},
                 {0,1,0,1,0,0,0,0},
                 {0,1,1,0,1,1,0,0},
                 {0,1,0,1,0,1,0,0},
                 {0,0,0,1,1,0,1,1},
                 {0,0,0,0,0,1,0,0},
                 {0,0,0,0,0,1,0,0}};
    int visited[]={0,0,0,0,0,0,0,0};
    BFS(AM,&front,&rear,visited,3);
    return 0;
}
