/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    int before=0;
    int after=0;
    ListNode ans;
    public ListNode middleNode(ListNode head) {
        if(head.next == null) return head;
        traversal(head);
        return ans;
    }
    public void traversal(ListNode head)
    {
        ans=head;
       while(head.next!=null)
       {
           head=head.next;
           after++;
           if(after-before>=2)
           {
            
               ans=ans.next;
               before++;
               after--;
               continue;
           }
            // System.out.println("123") ;
       }
       if(after!=before)
       {
           // System.out.println(after-before);
           ans=ans.next;
       }
    }
}