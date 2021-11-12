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
        data=d;
    }
};
int search(int inorder[],int start,int end, int x){
    for(int i = start;i<=end;i++){
        if(inorder[i]==x)
        return i;
    }
    return -1;
}
Tree* buildTree(int preorder[],int inorder[], int start, int end){
    static int c = 0;
    if(start>end) //border case to check
    return NULL;
    int x = preorder[c];
    Tree* curr = new Tree(x);
    c++;
    if(start==end) // leaf node which  does not have any node to left or right
    return curr;   

    int pos = search(inorder,start,end,x);
    curr->left=buildTree(preorder,inorder,start,pos-1); // filling up left subtree
    curr->right=buildTree(preorder,inorder,pos+1,end);  // filling up right subtree

    return curr;  // finally returning the root node

}
void inorder_print(Tree* root){
    if(root==NULL)
    return;
    inorder_print(root->left);
    cout<<root->data<<" ";
    inorder_print(root->right);
}
int main(){
    sync;
    int preorder[] = {1,2,4,3,5};
    int inorder[] = {4,2,1,5,3};
    Tree* root = buildTree(preorder,inorder,0,4);
    inorder_print(root);
    cout<<endl;
    return 0;
}