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
    int pathSum(TreeNode* root, int& sum){
        if(!root)return 0;
        int l = max(pathSum(root->left,sum),0);
        int r = max(pathSum(root->right,sum),0);
        sum = max(sum,l+r+root->val);
        return root->val+max(l,r);
    }
    int maxPathSum(TreeNode* root) {
        if(!root)return 0;
        int sum=INT_MIN;
        pathSum(root,sum);
        return sum;
    }
};