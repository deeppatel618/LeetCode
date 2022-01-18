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
    public ListNode removeElements(ListNode head, int val) {
       if(head ==  null || (head.val==val && head.next==null)) return null;
        while(head!=null && head.val==val ) {
            head=head.next;
        }
        ans=head;
        while(head!=null && head.next!=null){
            if(head.next.val==val)
            {
                head.next=head.next.next;
            }else{
            head=head.next;}
        }
        return ans;
    }
}