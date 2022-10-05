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
    void solve(TreeNode* root, int val, int depth, int curDepth){
        if(!root)return;
        if(depth-1>curDepth){
            solve(root->left,val,depth,curDepth+1);
            solve(root->right,val,depth,curDepth+1);
            return;
        }
        TreeNode* newNode1 = new TreeNode(val);
        TreeNode* newNode2 = new TreeNode(val);
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        root->left=newNode1;
        root->right=newNode2;
        newNode1->left=left;
        newNode2->right=right;
        return;
    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(!root)return root;
        if(depth==1){
            TreeNode* newHead = new TreeNode(val);
            newHead->left=root;
            return newHead;
        }
        solve(root,val,depth,1);
        return root;
    }
};