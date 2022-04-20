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
class BSTIterator {
private:
    TreeNode* Root=NULL;
    int iter=0;
    vector<int> inOrder;
    int n;
    void traverse(TreeNode* root){
        if(!root)return;
        traverse(root->left);
        inOrder.push_back(root->val);
        traverse(root->right);
        return;
    }
public:
    
    BSTIterator(TreeNode* root) {
        this->Root=root;
        traverse(root);
        n=inOrder.size();
    }
    
    int next() {
        if(hasNext())return inOrder[iter++];
        return NULL;
    }
    
    bool hasNext() {
        if(iter<n)return true;
        else return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */