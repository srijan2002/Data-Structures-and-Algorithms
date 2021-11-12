#include<bits/stdc++.h>
using namespace std;
#define sync ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
class Node{
   public:
   int data;
   Node* next; 
   Node* prev;
};

void add_front(Node** head, int d){
    Node* temp  = new Node();
    temp->data=d;
    temp->next=*head;
    temp->prev=NULL;
    if((*head) !=NULL)
    (*head)->prev=temp;

    (*head)=temp;
}
void add_end(Node** head, int d){
    Node* temp = new Node();
    Node* last = *head;
    while(last->next!=NULL)
    last=last->next;

    temp->data=d;
    temp->next=NULL;

    if((*head)==NULL){
        temp->prev=NULL;
        *head=temp;
        return;
    }
    temp->prev=last;
    last->next=temp;
    return;
}
 

int main(){
    sync;
    int c = 0; cin>>c;
      Node* head = new Node();
     head = NULL;
    while(c!=0){
        int d=0;
        
        if(c==1){
         cin>>d;
            if(head==NULL){
                 head = new Node();
                 head->data=d; head->next=NULL; head->prev=NULL;
                 cout<<head<<endl;
            }
            else
             add_end(&head,d);
        }
       
          if(c==2){
                cin>>d;
                 if(head==NULL){
                 head = new Node();
                 head->data=d; head->next=NULL; head->prev=NULL;
            }
            else
             add_front(&head,d);
        }
        
        cin>>c;
    }
    
  
    cout<<endl;
    return 0;
}