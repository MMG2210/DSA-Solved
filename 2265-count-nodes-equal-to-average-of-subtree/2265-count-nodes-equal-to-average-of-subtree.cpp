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
    
    pair<int,int> getAverage(TreeNode* root){
        if(!root)return {0,0};
        
        auto l_sub = getAverage(root->left);
        auto r_sub = getAverage(root->right);
        
        int sum = l_sub.first + r_sub.first + root->val;
        int cnt = l_sub.second + r_sub.second + 1;
        if(root->val==sum/cnt)res++;
        
        return {sum,cnt};
    }
    
    int averageOfSubtree(TreeNode* root) {
        getAverage(root);
        return res;
    }
};