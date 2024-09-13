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
    ListNode* rotateRight(ListNode* head, int k) {
       if(k==0 || head == NULL) return head;
       ListNode *low = head, *high = head;
       int counter = 1;
       while(high->next != NULL )
       {
            high = high->next;
            counter+=1;
       }
    //    cout<<counter;
    counter = k % counter;
    high = head;
    while(counter !=0)
    {
        high= high->next;
        counter-=1;
    }
    while(high->next!=NULL)
    {
        low = low->next;
        high = high->next;
    }
    high->next = head;
    ListNode *ans = low->next;
    low->next = NULL;
    return ans;
    }
};