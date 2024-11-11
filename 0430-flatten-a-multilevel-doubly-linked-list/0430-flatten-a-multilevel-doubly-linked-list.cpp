/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flattenDFS(Node* prev, Node* curr)
    {
        if(curr == NULL) return prev;
        //Swapping operation prev->Cur and prev<-Cur
        curr->prev = prev;
        prev->next = curr;

        // Storing the next of curr.
        Node* tempNext = curr->next;

        Node* tail = flattenDFS(curr, curr->child);
        //removing child
        curr->child = NULL; 

        return flattenDFS(tail,tempNext);


    }
    Node* flatten(Node* head) {
        if (head == NULL) return head;
        // pseudo head to ensure the prev pointer is never none
        Node *pseudoHead = new Node(0, NULL, head, NULL);
        flattenDFS(pseudoHead, head);

        // detach the pseudo head from the real head
        pseudoHead->next->prev = NULL;
        return pseudoHead->next;
    }
};