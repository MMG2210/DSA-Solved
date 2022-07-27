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
// class Solution {
// public:
//     void flatten(TreeNode* root) {
//         if(!root)return;
//         TreeNode* cur = root;
//         while(cur!=NULL)
//         {
//             if(cur->left!=NULL)
//             {
//                 TreeNode *temp = cur->left;
//                 while(temp->right!=NULL)
//                     temp=temp->right;
//                 temp->right = cur->right;
//                 cur->right = cur->left;
//                 cur->left = NULL;
//                 cur=cur->right;
//             }
//             else cur=cur->right;
//         }
//     }
// };O(N),O(1)
class Solution {
public:
    vector<string> pre;
    
    void preOrder(TreeNode* root){
        if(!root){
            pre.push_back("$");
            return;
        }
        preOrder(root->left);
        pre.push_back(to_string(root->val));
        preOrder(root->right);
    }
    
    void flatten(TreeNode* root) {
        if(!root)return;
        TreeNode* temp=root->right;
        root->right=root->left;
        root->left=nullptr;
        TreeNode* node=root;
        while(node->right!=NULL){
            node=node->right;
        }
        node->right=temp;
        flatten(root->right);
    }
};