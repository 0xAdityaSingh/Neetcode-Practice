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
    int diameter = INT_MIN;
    int helper(TreeNode* root){
        if(!root) return 0;
        int leftDiameter = helper(root->left);
        int rightDiameter = helper(root->right);
        diameter = max(diameter, leftDiameter+rightDiameter);
        return max(leftDiameter,rightDiameter)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        helper(root);
        return diameter;
    }
};
