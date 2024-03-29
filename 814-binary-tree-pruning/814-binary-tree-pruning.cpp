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
    
    TreeNode* helper(TreeNode* root){
       if(root!=NULL){
           root->left=helper(root->left);
           root->right=helper(root->right);
           if(root->val==0){
               if(root->left==nullptr && root->right==nullptr)root=nullptr;
           }
        }
        return root;
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        return helper(root);
    }
};