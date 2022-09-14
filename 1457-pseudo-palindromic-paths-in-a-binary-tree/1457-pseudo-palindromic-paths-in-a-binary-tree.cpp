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
    
    void solve(TreeNode* root, vector<int> cnt){
        if(!root)return;
        cnt[root->val]++;
        if(!root->left && !root->right){
            int eve=0,odd=0;
            for(int& i:cnt){
                if(i>0){
                    if(i&1)odd++;
                    else eve++;
                }
            }
            if(odd<=1)res++;
            return;
        }
        solve(root->left,cnt);
        solve(root->right,cnt);
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        if(!root)return res;
        vector<int> cnt(10);
        solve(root, cnt);
        return res;
    }
};