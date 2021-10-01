#include<stdio.h>
#include<stdlib.h>
#define f(i,a,b)    for(int i=a;i<b;i++)
typedef struct Queue {
    int front,back,size;
    int* arr;
}queue;

queue* createQueue(int sz)
{
    queue* QueueInit = (queue*)malloc(sizeof(queue));
    QueueInit->size = sz;
    QueueInit->arr = (int *)malloc(sizeof(QueueInit->size * sizeof(int)));
    QueueInit->front = -1;
    QueueInit->back  = -1;
    return QueueInit;

}
int isFull(queue* Qu){
    return Qu->back == Qu->size-1;
}
int isEmpty(queue* Qu){
    return Qu->back == Qu->front;
}
void enqueue(queue **Qu, int x){
    if(isFull(*Qu)){
        printf("Overflow\n");
    } else {
        (*Qu)->arr[(*Qu)->back++] = x;
    }
}
void dequeue(queue **Qu){
    if(isEmpty(*Qu)){
        printf("Underflow\n");
    } else {
        printf("%d was de-queued\n",(*Qu)->arr[(*Qu)->front]);
        (*Qu)->front++;
    }
}
void display(queue *Qu){
    f(i,Qu->front,Qu->back){
        printf("%d >> ",Qu->arr[i]);
    }
    printf("earthed\n");
}
int main()
{
    int n;  scanf("%d",&n);
    queue* Q = createQueue(n);
    f(i,0,n){
        int val;    scanf("%d",&val);
        enqueue(&Q,val);
    }
    display(Q);
    dequeue(&Q);
    display(Q);
    return 0;
}
