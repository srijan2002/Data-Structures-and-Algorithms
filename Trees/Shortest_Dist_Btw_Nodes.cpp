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
    return NULL;
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
int dist(Tree* root, int n, int dis){
    if(root==NULL) // base case when node not found even after traversing till leaf nodes
    return -1;
    if(root->data==n) // current node
    return dis;  
    int left = dist(root->left,n,dis+1); // searching in left node
    if(left!=-1)
    return left;  // if exists in left return
    return dist(root->right,n,dis+1); // else return from right
}
int sum(Tree* root, int n1,int n2){
    Tree* lca = LCA(root,n1,n2);
    int a = dist(lca,n1,0);
    int b = dist(lca,n2,0);
    return a+b;
}
int main(){
    Tree* root = new Tree(1);
    root->left = new Tree(2);
    root->right = new Tree(3);
    root->left->left = new Tree(4);
    root->left->right = new Tree(5);
    root->right->left = new Tree(6);
    root->right->right = new Tree(7);
    cout<<sum(root,4,2)<<endl;
    return 0;
}