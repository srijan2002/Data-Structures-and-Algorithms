<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;
#define sync ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
class Node{
   public:
   int data;
   Node* next; 
};
Node* reverseList(Node* head){
    Node* current = new Node();
    current  = head;
    Node* next = new Node();
    Node* prev = NULL;
    while(current!=NULL){
        next = current->next;
        current->next=prev;
        prev=current;
        current = next;
    }
    return prev;
}
int main(){
    Node* head = new Node();
    // INPUT 
    Node* rev = reverseList(head);
=======
//Reversing a Linked List
#include<iostream>
using namespace std;

class node {
    public:
    int data;
    node* next;

    //Constructor
    node(int val){
        data = val;
        next = NULL;
    }
};
void print(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" >> ";
        temp = temp->next;
    } cout<<">> earthed"<<"\n";
}
void push(node* &head,int val){
    node* new_node = new node(val);
    if(head==NULL){
        head = new_node;
    } else {
        node* ptr = head;
        while(ptr->next){
            ptr = ptr->next;
        }
        ptr->next = new_node;
        new_node->next = NULL;

    }
}
node* reverse(node* &root){
    // 3 pointer method
    node* prev = NULL;
    node* curr = root;
    node* future;
    while(curr!=NULL){
        future = curr->next;
        curr->next = prev;
        prev = curr;
        curr = future; 
    }
    return prev;
}
node* Re_reverse(node* &root){
    //Recursive call to reverse a linkedlist
    if(root==NULL || root->next==NULL){
        return root;
    }
    //Seding back a list to reverse
    node* callback = Re_reverse(root->next);
    // Changing to the next of next node so that we get towards the head node
    root->next->next = root;
    // Changing it to NULL
    root->next = NULL;
    //Passing up the new reversed head-node 
    return callback;
}
int main(){
    int n;  cin>>n;
    node* root = NULL;
    for(int i=0;i<n;i++){
        int val;    cin>>val;
        push(root,val);
    }
    print(root);
    cout<<"Reversed List is : \n";
    node* rev_root = reverse(root);
    print(rev_root);
>>>>>>> 7e0685ea97ab1d4f41a4086babc548accd318acb
    return 0;
}