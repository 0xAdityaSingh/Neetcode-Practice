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
    int ans=INT_MIN;
    int func(TreeNode* root){
        if(!root) return 0;
        int l=max(func(root->left),0);
        int r=max(func(root->right),0);
        ans=max(ans,l+r+root->val);
        return root->val+max(r,l);
    }
    int maxPathSum(TreeNode* root) {
        func(root);
        return ans;
    }
};