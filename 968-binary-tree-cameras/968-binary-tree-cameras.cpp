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
    int ans = 0;
    
    int solve(TreeNode* root){
        if(root==NULL)return 2;
        int lh = solve(root->left);
        int rh = solve(root->right);
        if(lh==0 || rh==0){
            ans++;
            return 1;
        }
        if(lh==1 or rh==1)return 2;
        return 0;
    }
    
    int minCameraCover(TreeNode* root) {
        return (solve(root)<1?1:0) + ans;
    }
};