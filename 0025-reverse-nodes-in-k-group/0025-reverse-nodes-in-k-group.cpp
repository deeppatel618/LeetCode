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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k==1) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode *curr= dummy, *nex=dummy,*prev=dummy;
        // ListNode* nex;
        // curr = head;
        int counter=0;
        while(curr->next!=NULL)
        {
            counter+=1;
            curr = curr->next;
        }
        
        while(counter>=k)
        {
        curr = prev->next;
        nex = curr->next;
        for(int i=1;i<k;i++ )
        {
            curr->next = nex->next;
            nex->next = prev->next;
            prev->next = nex;
            nex = curr->next;
        }
        prev=curr;
        counter-=k;
        }
        return dummy->next;
    }
};