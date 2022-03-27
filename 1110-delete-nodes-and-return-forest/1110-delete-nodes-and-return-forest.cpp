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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> res;
        set<int>toDelete;
        for(int &it : to_delete)
            toDelete.insert(it);
        helper(root, res, toDelete);
        if(toDelete.find(root->val)==toDelete.end())res.push_back(root);
        return res;
    }
    TreeNode* helper(TreeNode* root, vector<TreeNode*>& res, set<int>& toDelete){
        if(!root)return NULL;
        root->left = helper(root->left,res,toDelete);
        root->right = helper(root->right,res,toDelete);
        if(toDelete.find(root->val)!=toDelete.end()){
            if(root->left)res.push_back(root->left);
            if(root->right)res.push_back(root->right);
            return NULL;
        }
        return root;
    }
};