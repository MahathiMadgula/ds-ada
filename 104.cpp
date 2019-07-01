//https://leetcode.com/problems/maximum-depth-of-binary-tree/
// Problem-no: 104
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
    int maxDepth(TreeNode* root) {
        if(root==NULL)  return 0;
        else
            return max(1+maxDepth(root->left),1+maxDepth(root->right));
    }
};
