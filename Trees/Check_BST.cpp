#include<bits/stdc++.h>
typedef long long int lli;
#define sync ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
class Tree{
  public:
    int data;
    Tree* left;
    Tree* right;

    Tree(int d){
        data = d;
    }
};

bool isBST(Tree* root, Tree* min, Tree* max){
    if(root==NULL)
     return true;

    if(min!=NULL && root->data<= min->data){
     return false;
     
    }
    if(max!=NULL && root->data>= max->data){
     return false;
    }
    bool left = isBST(root->left,min,root);
    bool right = isBST(root->right,root,max);

    return left&&right;  
}

int main(){

    sync;
    Tree* root = new Tree(4);
    root->left = new Tree(2); root->right = new Tree(6);
    root->left->left = new Tree(1); root->left->right = new Tree(3);
    root->right->left = new Tree(5);  root->right->right = new Tree(7);
    if(isBST(root,NULL,NULL))
    cout<<"Is BST"<<endl;
    else
    cout<<"Not a BST"<<endl;
return 1;
}
