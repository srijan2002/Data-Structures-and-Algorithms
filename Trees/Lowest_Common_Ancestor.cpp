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

Tree* LCA(Tree* root, int n1, int n2){
    if(root==NULL)
    return NULL;   // after traversing leaf node

    if(root->data==n1 || root->data==n2)
    return root;

    Tree* left = LCA(root->left,n1,n2);
    Tree* right = LCA(root->right,n1,n2);

    if(left && right)
    return root;

    if(left!=NULL)
    return left;
    
    return right;

}
int main(){
    
      Tree* root = new Tree(1);
    root->left = new Tree(2);
    root->right = new Tree(3);
    root->left->left = new Tree(4);
    root->left->right = new Tree(5);
    root->right->left = new Tree(6);
    root->right->right = new Tree(7);
    Tree* res = LCA(root,7,4);
    if(res)
    cout<<res->data<<endl;
    else
    cout<<"Not Found"<<endl;
}