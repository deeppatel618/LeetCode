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
    ListNode* reverse(ListNode* node) {
    ListNode* prev = nullptr;  
    ListNode* curr = node;     

    while (curr != nullptr) {
        ListNode* nextNode = curr->next; 
        curr->next = prev;  
        prev = curr;        
        curr = nextNode;    
    }
    return prev;
}

    ListNode* findMiddle(ListNode* node){
        ListNode* slow = node;
        ListNode* fast = node;
        while(fast && fast->next!=nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next) return; 

        ListNode* middle = findMiddle(head);
        
        ListNode* ptr2 = reverse(middle->next);
        middle->next = nullptr;

        ListNode* ptr1 = head;
        
        while (ptr1 && ptr2) {
            ListNode* temp1 = ptr1->next;
            ListNode* temp2 = ptr2->next;

            ptr1->next = ptr2;
            ptr2->next = temp1;

            ptr1 = temp1;
            ptr2 = temp2;
        }
    }
};