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
    int getSum(TreeNode* root){
        if(!root)return 0;
        return root->val+getSum(root->left)+getSum(root->right);
    }
    
    void helper(TreeNode* root){
        if(!root)return;
        if(getSum(root->left)==0)root->left=nullptr;
        else helper(root->left);
        if(getSum(root->right)==0)root->right=nullptr;
        else helper(root->right);
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        helper(root);
        if(getSum(root)==0)return nullptr;
        return root;
    }
};