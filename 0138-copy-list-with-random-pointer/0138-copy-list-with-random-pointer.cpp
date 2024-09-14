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
    Node* copyRandomList(Node* head) {
        Node *temp = head;
        while(temp != NULL)
        {
            Node *newNode = new Node(temp->val);
            // newNode->val = temp->val;
            newNode->next = temp->next;
            temp->next = newNode;
            temp = newNode->next;
        }
        temp = head;
        while(temp != NULL)
        {
            if(temp->random != NULL)
            {
                temp->next->random = temp->random->next; 
            }
            temp = temp->next->next;
        }
        temp = head;
        Node *dummy =new Node(-1);
        Node *ans =dummy;
        while(temp != NULL )
        {
            ans->next = temp->next;
            temp->next = temp->next->next;
            ans = ans->next;
            temp = temp->next;
        }
        return dummy->next;
    }
};