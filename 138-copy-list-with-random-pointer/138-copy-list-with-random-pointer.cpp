/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    /*Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> m;
        Node* ptr = head;
        while(ptr)
        {
            m[ptr]=new Node(ptr->val);
            ptr=ptr->next;
        }
        ptr=head;
        while(ptr)
        {
            m[ptr]->next = m[ptr->next];
            m[ptr]->random = m[ptr->random]; TC - O(N) , SC - O(N)
            ptr=ptr->next;
        }
        return m[head];
    }*/
     Node* copyRandomList(Node* head) {
         if(head==NULL)
            return NULL;
         Node* ptr = head;
         while(ptr)
         {
             Node* temp = new Node(ptr->val);
             temp->next = ptr->next;
             ptr->next = temp;
             ptr=temp->next;
         }
         ptr = head;
         while(ptr)
         {
             ptr->next->random = (ptr->random)? ptr->random->next:NULL;
             ptr=ptr->next->next;
         }
         Node* copy = head->next;
         ptr=head;
         Node* cur = copy;
         while(ptr)
         {
             ptr->next=ptr->next->next;
             copy->next = (!copy->next)?NULL:copy->next->next;
             copy=copy->next;
             ptr=ptr->next;
         }
         return cur;
     }
};