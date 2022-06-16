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
    bool dfs(TreeNode* curr, TreeNode* root, int k){
        if(!curr)return 0;
        
        return search(root, curr,k-curr->val)||dfs(curr->left,root,k)||dfs(curr->right,root,k);
    }
    
    bool search(TreeNode* curr,TreeNode* root, int k){
        if(!curr)return false;
        if(curr!=root && curr->val==k)return 1;
        else return search(curr->left,root,k)||search(curr->right,root,k);
    }
    
    bool findTarget(TreeNode* root, int k) {
        return dfs(root, root, k);
    }
};