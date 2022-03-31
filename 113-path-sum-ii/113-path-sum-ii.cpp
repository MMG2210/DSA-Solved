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
    void helper(int target, TreeNode* root, vector<int> temp, vector<vector<int>>& res){
        if(!root)return;
        temp.push_back(root->val);
        target-=root->val;
        if(target==0 && !root->left && !root->right){
            res.push_back(temp);
            return;
        }
        helper(target,root->left,temp,res);
        helper(target,root->right,temp,res);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        if(!root)return res;
        helper(targetSum,root,vector<int>(),res);
        return res;
    }
};