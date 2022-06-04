/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
         queue<TreeNode*> q; bool flag = false;
        q.push(root);  
        q.push(NULL);
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(temp){
                
                if(temp->left){
                    if(flag) // if non full node already present before
                        return false;
                     q.push(temp->left);
                }else
                    flag=true; // setting this node as non full node
                   
                if(temp->right){
                    if(flag)
                        return false;
                     q.push(temp->right);
                }else
                    flag = true;
                   
            }
            else if(!q.empty()){
                q.push(NULL);
                
            }
        }
         
        return true; // passed all the conditions above, so a complete tree
    }
};