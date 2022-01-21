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
    ListNode ans;
    ListNode traversal;
    int before=1;
    public ListNode removeNthFromEnd(ListNode head, int n) {
        if(head.next==null && n==1) return null;
        ans=head;
        traversal=head;
        while(traversal.next!=null)
        {
            traversal=traversal.next;
            before++;
            if(before>n+1)
            {
                head=head.next;
                before--;
            }
        }
        if(head.next.next==null && before == n+1)
        {
            head.next=null;
        }
        else if(before == n+1){
            head.next=head.next.next;
        }
        else
        {
            ans=ans.next;
        }
        return ans;
    }
}