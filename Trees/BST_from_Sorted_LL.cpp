/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    ListNode* curr;
    TreeNode* treeify(int i, int j) {
        if (j < i) return nullptr;
        int mid = (i + j) >> 1;
        TreeNode* node = new TreeNode();
        node->left = treeify(i, mid - 1);
        node->val = curr->val, curr = curr->next;
        node->right = treeify(mid + 1, j);
        return node;
    }
     TreeNode* sortedListToBST(ListNode* head) {
        int count = 0;
        curr = head;
        while (curr) curr = curr->next, count++;
        curr = head;
        return treeify(1, count);
    }
};