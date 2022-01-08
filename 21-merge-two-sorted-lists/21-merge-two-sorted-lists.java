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
  public ListNode lastNode(int ind,int[] a,int index)
    {
        ListNode obj2=new ListNode();
        if(ind==index){
            obj2.val=a[index];
            obj2.next=null;
            return obj2;
        }
        else{
            
            obj2.val=a[ind];
            ind++;
            obj2.next=lastNode(ind,a,index);
        }
      return obj2;
    }
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
             
         if(list1 == null && list2 ==null) return list1;
        if (list1 == null) return list2;
        if (list2 == null) return list1;
        ListNode obj1= new ListNode();
        int[] a=new int[100];
        int index=-1;
        while(list1 != null && list2 != null)
        {
            if(list1.val<=list2.val )
            {
                index++;
                a[index]= list1.val;
                list1=list1.next;
            }
            else
            {
                index++;
                a[index]=list2.val;
                list2=list2.next;
            }
        }
        while (list1!=null)
        {
            index++;
            a[index]= list1.val;
            list1=list1.next;        
        }
        while (list2!=null)
        {
            index++;
            a[index]= list2.val;
            list2=list2.next;
        }
       obj1.val=a[0];
        obj1.next=lastNode(1,a,index);
        return obj1;
    }
    
}