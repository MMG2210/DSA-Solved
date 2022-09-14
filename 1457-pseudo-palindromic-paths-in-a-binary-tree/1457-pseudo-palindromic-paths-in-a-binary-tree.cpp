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
    
    void solve(TreeNode* root, int& mask){
        if(!root)return;
        if(!root->left && !root->right){
            int odd=0;
            for(int i=0;i<31;i++){
                if(mask&(1<<i))odd++;
            }
            if(odd<=1)res++;
            return;
        }
        if(root->left){
            mask^=(1<<root->left->val);
            solve(root->left,mask);
            mask^=(1<<root->left->val);
        }
        if(root->right){
            mask^=(1<<root->right->val);
            solve(root->right,mask);
            mask^=(1<<root->right->val);
        }
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        if(!root)return res;
        int mask=0;
        mask^=(1<<root->val);
        solve(root, mask);
        return res;
    }
};