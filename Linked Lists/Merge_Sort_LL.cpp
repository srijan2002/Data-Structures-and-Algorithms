#include<bits/stdc++.h>
using namespace std;
#define sync ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long int lli;

class Node{
 public:
    int data;
    Node* next;
};
void divide(Node* head, Node** a, Node** b){
    Node* current = head;
    Node* next = current->next;
    while(next!=NULL){
        next = next->next;
        if(next!=NULL){
            current=current->next;
            next = next->next;  
        }
    }
    *a = head;
    *b = current->next;
      current->next=NULL;
}
Node* merge(Node** a, Node** b){
    Node* head = new Node();
    head->data=min((*a)->data,(*b)->data);
        if((*a)->data< (*b)->data)
        (*a)=(*a)->next;
        else
        (*b)=(*b)->next;
    Node* copy = head;
    while(*a!=NULL && *b!=NULL){
        Node* node = new Node();
        node->data=min((*a)->data,(*b)->data);
        if((*a)->data< (*b)->data)
        (*a)=(*a)->next;
        else
        (*b)=(*b)->next;
        head->next=node;
        head=head->next;
    }
    if((*a)==NULL){
        while((*b)!=NULL){
            Node* node = new Node();
            node->data=(*b)->data;
            (*b)=(*b)->next;
            head->next=node;
            head=head->next;
        }
    }
    else{
         while((*a)!=NULL){
             Node* node = new Node();
            node->data=(*a)->data;
            (*a)=(*a)->next;
             head->next=node;
            head=head->next;
        }
    }
    head->next=NULL;
    return copy;
}
void mergeSort(Node** h){
  Node* head = *h; 
    Node* a; Node* b;
    if (((head) == NULL) || ((head)->next == NULL)) {
        return;
    }
      divide(head, &a, &b);

      mergeSort(&a); mergeSort(&b);
     *h =  merge(&a,&b);
}


void printList(Node* node)
{
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout<<endl;
}
 
/* Function to insert a node at the beginning of the linked list */
void push(Node** head_ref, int new_data)
{
    /* allocate node */
    Node* new_node = new Node();
 
    /* put in the data */
    new_node->data = new_data;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref) = new_node;
}
 
int main(){
    Node* res = NULL;
    Node* a = NULL;
  
    push(&a, 15);
    push(&a, 10);
    push(&a, 5);
    push(&a, 20);
    push(&a, 3);
    push(&a, 2);
 
    
    mergeSort(&a);
 
    cout << "Sorted Linked List is: \n";
    printList(a);
 
    return 0;
}
 