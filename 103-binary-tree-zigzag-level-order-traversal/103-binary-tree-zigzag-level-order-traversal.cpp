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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==NULL)return res;
        queue<TreeNode*> q;
        q.push(root);
        int flag=0;
       while(!q.empty()){
           vector<int> temp;
           int s = q.size();
           for(int i=0;i<s;i++){
               auto node = q.front();q.pop();
               if(node->left)q.push(node->left);
               if(node->right)q.push(node->right);
               temp.push_back(node->val);
           }
           if(flag==0)flag=1;
           else{
               flag=0;
               reverse(begin(temp),end(temp));
           }
           res.push_back(temp);
       }
        return res;
    }
};