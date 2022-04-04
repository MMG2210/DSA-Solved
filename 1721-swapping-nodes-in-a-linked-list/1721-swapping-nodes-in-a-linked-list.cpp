/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *f=head, *s=head, *sf = head;
        int i=0;
        while(i<k-1){
            f=f->next;
            sf=sf->next;
            i++;
        }
        while(f!=NULL && f->next!=NULL){
            f=f->next;
            s=s->next;
        }
        swap(s->val,sf->val);
        return head;
    }
};