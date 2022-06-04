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
    vector<int> V; int temp = 0;
    int Sum(TreeNode* root){
         if(!root)
            return 0;
        if(root->left || root->right)
        {
            int x = Sum(root->left)+Sum(root->right)+root->val;
            V.push_back(x);
            return x;
        }else{
            V.push_back(root->val);
            return root->val;
        }
        
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
          int x = Sum(root);
         unordered_map<int,int> M; vector<int> res;
        for(auto i:V)
            M[i]++;
        
        int mx = -1;
        for(auto i:M)
            mx = max(mx,i.second);
        
          for(auto i:M)
            { 
              if(i.second == mx)
                  res.push_back(i.first);
          }
        return res;
    
    }
};