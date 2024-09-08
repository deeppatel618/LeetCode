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
        ListNode *a;
        ListNode *b;
        a = headA;
        b = headB;
        while( a!=NULL || b!=NULL)
        {
            if(a->val == b->val && a == b)
            {
                return a;
            }
            a = a->next;
            b = b->next;
            if(a == NULL && b!=NULL)
            {
                a = headB;

            }
            else if(b == NULL && a!=NULL)
            {
                b = headA;
            }
        }
        return NULL;
    }
};