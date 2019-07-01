//https://leetcode.com/problems/merge-two-binary-trees/
//Problem-no: 617
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(!t1 && !t2)  return NULL;
        if(t1 && !t2)   return t1;
        if(t2 && !t1)   return t2;
        TreeNode* head=new TreeNode(t1->val+t2->val);
        head->left=mergeTrees(t1->left,t2->left);
        head->right=mergeTrees(t1->right,t2->right);
        return head;
    }
};
