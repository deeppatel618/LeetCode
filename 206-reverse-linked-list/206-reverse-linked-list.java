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
    
    public ListNode ans = null;
    public void reverseRecur(ListNode prev,ListNode head){
        if(head==null){
            ans = prev;
            return;
            
        }
        reverseRecur(head,head.next);
        prev.next = null;
        head.next = prev;
    }
    public ListNode reverseList(ListNode head) {
            if(head!=null)
            reverseRecur(head,head.next);
            return ans;
    }
}