/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode head, cur;
        ListNode p1 = l1, p2 = l2;
        
        int sum = 0, carry = 0;
        sum = l1.val + l2.val;
        if(sum >= 10) {
            carry = 1;
            sum -= 10;
        }
        head = new ListNode(sum);
        cur = head;
        l1 = l1.next;
        l2 = l2.next;
        
        while(l1 != null && l2 != null) {
            // System.out.println("l1"+l1.val+"l2"+l2.val);
            sum = l1.val + l2.val + carry;
            if(sum >= 10) {
                carry = 1;
                sum -= 10;
            } else {
                carry = 0;
            }
            cur.next = new ListNode(sum);
            cur = cur.next;
            l1 = l1.next;
            l2 = l2.next;
        }

        while(l1 != null) {
            sum = l1.val + carry;
            if(sum >= 10) {
                carry = 1;
                sum -= 10;
            } else {
                carry = 0;
            }
            cur.next = new ListNode(sum);
            cur = cur.next;
            l1 = l1.next; 
        }
        while(l2 != null) {
            sum = l2.val + carry;
            if(sum >= 10) {
                carry = 1;
                sum -= 10;
            } else {
                carry = 0;
            }
            cur.next = new ListNode(sum);
            cur = cur.next;
            l2 = l2.next; 
        }
        if(carry > 0) {
            cur.next = new ListNode(carry);
        }
        return head;
    }
}