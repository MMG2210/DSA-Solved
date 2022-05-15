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
    //int h=INT_MIN;
    
//     int findMaxHeight(TreeNode* root){
//         if(!root)return 0;
        
//         int lh=findMaxHeight(root->left);
//         int rh=findMaxHeight(root->right);
        
//         return 1+max(lh,rh);
//     }
    
//     int deepestLeavesSum(TreeNode* root) {
//         int lvls = findMaxHeight(root),res=0;
        
//         queue<TreeNode*> q;
//         int curLevel=1;
//         q.push(root);
//         q.push(NULL);
//         while(!q.empty()){
//             TreeNode* f=q.front();q.pop();
//             if(f==NULL){
//                 if(q.empty())break;
//                 curLevel++;
//                 q.push(NULL);
//             }
            
//             else{
//                 if(f->left)q.push(f->left);
//                 if(f->right)q.push(f->right);
//                 if(curLevel==lvls){
//                     res+=f->val;
//                 }
//             }
//         }
        
//         return res;
//     }
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*> q;
        int res=0,i;
        q.push(root);
        while(!q.empty()){
            for(i=q.size()-1,res=0;i>=0;i--){
                TreeNode* node=q.front(); q.pop();
                res+=node->val;
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
        }
        
        return res;
    }
};