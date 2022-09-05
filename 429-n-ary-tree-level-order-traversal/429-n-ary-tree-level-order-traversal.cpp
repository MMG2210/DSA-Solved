/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if(!root)return res;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> temp;
            int sz=q.size();
            while(sz--){
                auto node = q.front(); q.pop();
                for(auto child : node->children){
                    q.push(child);
                }
                temp.push_back(node->val);
            }
            res.push_back(temp);
        }
        return res;
    }
};