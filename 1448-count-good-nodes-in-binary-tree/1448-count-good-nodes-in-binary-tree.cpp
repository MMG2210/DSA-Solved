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
    int res=0;
    
    void count(TreeNode* root, int maxi){
        if(!root)return;
        if(root->val>=maxi){
            res++;
            maxi=root->val;
        }
        count(root->left,maxi);
        count(root->right,maxi);
    }
    
    int goodNodes(TreeNode* root) {
        count(root,-1e5);
        return res;
    }
};