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
    return 0;
}