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
    string preorder(TreeNode* root){
        if(!root)return "";
        string res=to_string(root->val);
        if(!root->left && !root->right)return res;
        string left=preorder(root->left);
        string right=preorder(root->right);
        res+="("+left+")";
        if(right!="")res+="("+right+")";
        return res;
    }
    
    string tree2str(TreeNode* root) {
        return preorder(root);
    }
};