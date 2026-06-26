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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL || root==p || root==q)return root;
        TreeNode* left=NULL;
        TreeNode* right=NULL;
        if(p->val<root->val || q->val<root->val) left= lowestCommonAncestor(root->left,p,q);
        if(p->val>root->val || q->val>root->val)   right= lowestCommonAncestor(root->right,p,q);
        if(left !=NULL && right!=NULL )return root;
        else if(left!=NULL)return left;
        else if(right!=NULL)return right;
        return NULL;
   
    }
};