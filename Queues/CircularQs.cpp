#include<iostream>
#define f(i,a,b)    for(int i=a;i<b;i++)
using namespace std;
class queue {
    int front,back,size;
    int* array;
    public:
    queue(int sz){
        front=back=0;
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
    if((back+1)%size==front){
        cout<<"Queue is Full\n";
    } else {
        back = (back+1)%size;
        array[back] = x;
    }
}
void queue::dequeue(){
    if(queue::isEmpty()){
        cout<<"Underflow\n";
    } else {
        cout<<array[front+1]<<" dequeued out\n";
        front = (front+1)%size;
    }
}

void queue::display(){
    int i = front+1;
    do{
        cout<<array[i]<<" >> ";
        i = (i+1)%size;
    }while(i!=(back+1)%size);
    cout<<"\n";
}
int main(){
    queue Q(5);
    f(i,0,4){
        int val;    scanf("%d",&val);
        Q.enqueue(val);
    }
    Q.display();
    Q.dequeue();
    Q.display();
    Q.enqueue(78);
    Q.display();
    Q.dequeue();
    Q.display();
    Q.enqueue(45);
    Q.display();
    return 0;
}