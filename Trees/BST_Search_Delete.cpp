#include<bits/stdc++.h>
typedef long long int lli;
#define sync ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

class Tree{
    public:
      int data;
      Tree* left; Tree* right;
      Tree(int d){
          data=d;
      }
};
void inorder(Tree* root){
    if(root==NULL)
    return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
bool searchBST(Tree* root, int k){
     if(root==NULL)
    return false;
    if(root->data==k)
    return true;
    if(k<root->data)
     return searchBST(root->left,k);
    else
     return searchBST(root->right,k); 
}
Tree* inorderSucc(Tree* root){
    Tree* c = root;
    while(c->left!=NULL)
    c=c->left;

    return c;
}
Tree* deleteBST(Tree* root, int k){
    if(k<root->data)
    root->left=deleteBST(root->left,k);
    else if(k>root->data)
    root->right=deleteBST(root->right,k);
    else{
        // case 1 & 2
        if(root->left==NULL)
        {
            Tree* temp = root->right;
        delete(temp);
        return temp;
        }
        else if(root->right==NULL){
             Tree* temp = root->left;
        delete(temp);
        return temp;
        }
        // case 3
        Tree* temp = inorderSucc(root->right);
        root->data = temp->data;
        root->right = deleteBST(root->right,temp->data);
    }
    return root;
}
int main(){
    Tree* root = new Tree(4);
    root->left = new Tree(2); root->right=new Tree(6);
    root->left->left=new Tree(1); root->left->right=new Tree(3);
    root->right->left = new Tree(5); root->right->right = new Tree(7);
    // if(searchBST(root,2))
    // cout<<"Present"<<endl;
    // else
    // cout<<"Not Present"<<endl;
    inorder(root);
    cout<<endl;
    root = deleteBST(root,4);
    inorder(root);
    cout<<endl;
    return 0;
}
