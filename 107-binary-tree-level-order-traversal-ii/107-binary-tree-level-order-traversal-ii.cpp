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
    int depth(TreeNode* root){
        if(root == NULL)return 0;
		//return the maximum depth of the tree so to find the levels
        return max(depth(root->right),depth(root->left))+1;
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root == NULL)return {};
        int d = depth(root);
		vector<vector<int>> levels(d,vector<int>({}));
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        levels[d-1].push_back(root->val);
        d--;
        while(!q.empty()){
            auto temp = q.front();q.pop();
            if(temp){
                if(temp->left){q.push(temp->left);levels[d-1].push_back(temp->left->val);}
                if(temp->right){q.push(temp->right);levels[d-1].push_back(temp->right->val);}
            }
            else{
                if(q.empty())break;
                d--;
                q.push(NULL);
            }
        }
        return levels;
    }
};