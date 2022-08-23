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
    int getLength(ListNode* head){
        int len=0;
        while(head){
            len++;
            head=head->next;
        }
        return len;
    }
    
    ListNode* reverse(ListNode* head, int len){
        ListNode* dummy = new ListNode(0);
        dummy->next=head;
        ListNode *prev=NULL,*cur=dummy->next,*next=NULL;
        int half=len/2;
        while(half-- && cur){
            prev=cur;
            cur=cur->next;
        }
        while(cur){
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        
        return dummy->next;
    }
    
    ListNode* reverse(ListNode* head){
        ListNode *prev=NULL, *cur=head, *next=NULL;
        while(cur){
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        vector<int> a;
        while(head){
            a.push_back(head->val);
            head=head->next;
        }
        int len=a.size();
        int i=0,j=len-1;
        while(i<j){
            if(a[i++]!=a[j--])return false;
        }
        return true;
    }
};