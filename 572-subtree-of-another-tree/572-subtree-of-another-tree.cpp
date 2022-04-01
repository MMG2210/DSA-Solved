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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(!s || !t){
            return s == t;
        }else{
            return isEqual(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
        }
    }
    bool isEqual(TreeNode* p, TreeNode* q){
        if(!p || !q){
            return p == q;
        }else{
            return p->val == q->val && isEqual(p->left, q->left) && isEqual(p->right, q->right);
        }
    }
};