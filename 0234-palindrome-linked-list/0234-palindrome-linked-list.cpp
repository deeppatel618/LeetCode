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
    ListNode* reverseLinkedlist(ListNode *head)
    {
        ListNode *curr = head;
        ListNode *prev = NULL;
        while(curr!=NULL)
        {
            ListNode *front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode *low=head;
        ListNode *high=head;
        
        while(high != NULL)
        {
            if(high->next == NULL)
            {
                low = low->next;
                break;
            } 
            low = low->next;
            high = high->next->next;
        }
        high = reverseLinkedlist(low);
        low = head;
        while(high!=NULL)
        {
            // cout<<high->val<<","<<low->val;
            if(high->val !=low->val)
            {
                return false;
            }
            high= high->next;
            low= low->next;
        }
        return true;

    }
};