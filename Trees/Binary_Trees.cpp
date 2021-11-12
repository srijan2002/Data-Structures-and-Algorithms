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
 Tree* delete_node(Tree* root,int key)
{
    if(root==NULL)
        return NULL;
    if(root->left==NULL && root->right==NULL)
    {
        if(root->data==key)
            return NULL;
        else
            return root;
    }
    Tree* key_node=NULL;
    Tree* temp;
    Tree* last;
    queue<Tree*> q;
    q.push(root);
    // Do level order traversal to find deepest
    // node(temp), node to be deleted (key_node)
      // and parent of deepest node(last)
    while(!q.empty())
    {
        temp=q.front();
        q.pop();
        if(temp->data==key)
            key_node=temp;
        if(temp->left)
        {
            last=temp;//storing the parent node
            q.push(temp->left);
        }
         if(temp->right)
        {
            last=temp;// storing the parent node
            q.push(temp->right);
        }
             
         
    }
      if(key_node!=NULL)
    {
        key_node->data=temp->data;//replacing key_node's data to deepest node's data
        if(last->right==temp)
            last->right=NULL;
        else
            last->left=NULL;
        delete(temp);
     }
    return root;
}
void inorder(Tree* root){
    if(root == NULL)
    return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main(){
    Tree* root = NULL; Tree* copy;
     int c = 0;
     cin>>c;
     while(c!=0){
          
       if(root==NULL){
          int d; cin>>d;
           root = new Tree(d); copy = root;
       }
       else{
           cout<<"LEFT OR RIGHT NODE?"<<endl;
           string x; cin>>x;
           int d; cin>>d;
           if(x=="left"){
               root->left=new Tree(d);
               root=root->left;
           }
           if(x=="right"){
               root->right=new Tree(d);
               root=root->right;
           }

       }
       cin>>c;
     }
    
     inorder(copy);
     cout<<endl;
     cout<<"Enter no. to be deleted"<<endl;
     int x;cin>>x;
     copy= delete_node(copy,x);
    inorder(copy);
    

 
}