#include<iostream>
#define f(i,a,b)    for(int i=a;i<b;i++)
using namespace std;
class queue {
    int front,back,size;
    int* array;
    public:
    queue(int sz){
        front=back=-1;
        size = sz;
        array = new int[this->size];
    }
    void enqueue(int x);
    void dequeue();
    void display();
    bool isFull();
    bool isEmpty();
};
bool queue::isFull(){
    return back==size-1;
}
bool queue::isEmpty(){
    return front==back;
}
void queue::enqueue(int x){
    if(queue::isFull()){
        cout<<"Queue is full\n";
    } else {
        array[back++] = x;
    }
}
void queue::dequeue(){
    if(queue::isEmpty()){
        cout<<"Underflow\n";
    } else {
        cout<<array[front]<<" dequeued out\n";
        front++;
    }
}

void queue::display(){
    for(int i=front;i<back;i++){
        cout<<array[i]<<" >>";
    }cout<<"\n";
}
int main(){
    queue Q(5);
    f(i,0,5){
        int val;    scanf("%d",&val);
        Q.enqueue(val);
    }
    Q.display();
    Q.dequeue();
    Q.display();
    return 0;
}