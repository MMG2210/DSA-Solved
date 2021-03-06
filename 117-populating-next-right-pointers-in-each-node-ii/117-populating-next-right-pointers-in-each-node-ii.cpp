/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    /*Node* connect(Node* root) {
        if(root==NULL)return root;
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            Node* temp = q.front();q.pop();
            if(temp){
                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);
                if(!q.empty())temp->next=q.front();
            }
            else{
                if(q.empty())break;
                q.push(NULL);
            }
        }
        return root;
        //TC - O(N),SC - O(N)
    }*/
    /*Node* connect(Node* root){
        if(!root)return NULL;
        Node* p = root->next;
        while(p){
            if(p->left){
                p=p->left;
                break;
            }
            if(p->right){
                p=p->right;
                break;
            }
            p=p->next;
        }
        if(root->right)root->right->next=p;
        if(root->left)root->left->next=root->right?root->right:p;
        connect(root->right);
        connect(root->left);
        return root;
    TC = O(N) , SC = O(1) , Auxilary Space = O(N)recursion
    }*/
    Node* connect(Node* root){
        Node* cur = root;
        while(cur){
            Node* dummy = new Node(0);
            Node* temp = dummy;
            while(cur){
                if(cur->left){
                    temp->next=cur->left;
                    temp=temp->next;
                }
                if(cur->right){
                    temp->next=cur->right;
                    temp=temp->next;
                }
                cur=cur->next;
            }
            cur=dummy->next;
        }
        return root;
    // TC = O(N) , SC = O(1)
    }
};