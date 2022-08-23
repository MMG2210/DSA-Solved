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
    ListNode* reverse(ListNode* head){
        ListNode *prev=nullptr, *cur=head, *next=nullptr;
        while(cur){
            next=cur->next;
            cur->next = prev;
            prev=cur;
            cur=next;
        }
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode *fast=head,*slow=head;
        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        slow = reverse(slow);
        while(head && slow){
            if(slow->val != head->val)return false;
            head=head->next;
            slow=slow->next;
        }
        return true;
    }
};