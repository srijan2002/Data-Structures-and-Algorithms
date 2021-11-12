#include<bits/stdc++.h>
using namespace std;
#define sync ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long int lli;

class Tree{
 public:   
    int data;
    Tree* left;
    Tree* right;

    Tree(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};
void sumKthLevel(Tree* root, int k){
    int l = 0; int s=0;
   if(root==NULL)
   return;
   queue<Tree*> q;
   q.push(root);
   q.push(NULL);

   while (!q.empty())
   {
      Tree* temp = q.front();
      q.pop();
      if(temp!=NULL){
          if(l==k)
          s+=temp->data;
          if(temp->left)
          q.push(temp->left);
          if(temp->right)
          q.push(temp->right);
      }
      else if(!q.empty()){
          l++; q.push(NULL); // we push NULL for the next level end when we counter a NULL at the current level
      }
     
   }
   cout<<s<<endl;
   
}
int main(){
    Tree* root = new Tree(1);
    root->left = new Tree(2);
    root->right = new Tree(3);
    root->left->left = new Tree(4);
    root->left->right = new Tree(5);
    root->right->left = new Tree(6);
    root->right->right = new Tree(7);
    int k = 0;cin>>k;
    sumKthLevel(root,k);
    
}