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
    /*vector<int> ascOrder;
    void inOrder(TreeNode* root){
        if(!root)return;
        inOrder(root->left);
        ascOrder.push_back(root->val);
        inOrder(root->right);
        return;
    }
    TreeNode* increasingBST(TreeNode* root) {
        if(!root)return root;
        inOrder(root);
        TreeNode* newRoot=new TreeNode(ascOrder[0]);
        TreeNode* cur=newRoot;
        for(int i=1;i<ascOrder.size();i++){
            TreeNode* temp=new TreeNode(ascOrder[i]);
            cur->right=temp;
            cur=cur->right;
        }
        return newRoot;*/
    TreeNode* increasingBST(TreeNode* root, TreeNode* tail = NULL) {
        if (!root) return tail;
        TreeNode* res = increasingBST(root->left, root);
        root->left = NULL;
        root->right = increasingBST(root->right, tail);
        return res;
    }
};