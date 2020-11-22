# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# （5,2,4,6,1,3）
#  new
#  2 4 8 10  7
class Solution:
    def insertionSortList(self, head: ListNode) -> ListNode:
        if head is None or head.next is None:
            return head

        newHead = ListNode(0)
        newHead.next = head

        prev = head
        cur = head.next
        while cur is not None:
            loopNode = newHead
            while loopNode.next != cur and loopNode.next.val <= cur.val:
                loopNode = loopNode.next
            
            if loopNode.next == cur:
                prev = cur
                cur = cur.next
                continue

            prev.next = cur.next
            cur.next = loopNode.next
            loopNode.next = cur
            cur = prev.next

        return newHead.next