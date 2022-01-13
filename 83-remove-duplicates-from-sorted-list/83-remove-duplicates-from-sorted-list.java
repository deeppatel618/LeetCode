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
    public ListNode deleteDuplicates(ListNode head) {
        ListNode prev = head;
        ListNode ans;
        if(head == null)
            return null;
        ans = head;
        while(head!=null){
            if(head.val == prev.val){
                prev.next = head.next;
            }
            else
                prev = head;
            head = head.next;
        }
        return ans;
    }
}