/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *d1=headA, *d2 = headB;
        int f1=0,f2=0;
        while(d1!=NULL && d2!=NULL)
        {
            if(d1==d2)return d1;
            d1=d1->next;
            if(d1==NULL && f1==0){d1=headB;f1++;}
            d2=d2->next;
            if(d2==NULL && f2==0){d2=headA;f2++;}
        }
        return NULL;
    }
};