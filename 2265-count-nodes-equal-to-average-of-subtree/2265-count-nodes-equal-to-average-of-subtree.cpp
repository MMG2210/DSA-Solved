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
    
    void getAverage(TreeNode* root){
        if(!root)return;
        
        long long avg=0; int countNodes=0;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            
            avg+=node->val;
            countNodes++;
            
            if(node->left)q.push(node->left);
            if(node->right)q.push(node->right);
        }
        
        avg/=countNodes;
        
        if(root->val==avg)res++;
        
        getAverage(root->left);
        getAverage(root->right);
        return;
    }
    
    int averageOfSubtree(TreeNode* root) {
        getAverage(root);
        return res;
    }
};