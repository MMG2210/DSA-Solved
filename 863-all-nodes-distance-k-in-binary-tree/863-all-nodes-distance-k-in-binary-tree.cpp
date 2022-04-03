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
    unordered_map<TreeNode*,TreeNode*> par;
    unordered_set<TreeNode*> vis;
    vector<int> res;
    
    void findParent(TreeNode* root){
        if(!root)return;
        if(root->left){par[root->left]=root;findParent(root->left);}
        if(root->right){par[root->right]=root;findParent(root->right);}
    }
    
    void dfs(TreeNode* root, int k){
        
        if(vis.find(root)!=vis.end())return;
        if(k==0){res.push_back(root->val);return;}
        vis.insert(root);
        
        if(root->left)dfs(root->left, k-1);
        if(root->right)dfs(root->right, k-1);
        TreeNode* p = par[root];
        if(p)dfs(p, k-1);
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        findParent(root);
        dfs(target,k);
        return res;
    }
};