# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:    
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        dummyNode = ListNode(-1)
        tailNode = dummyNode
        while True:
            minNodeIdx = -1
            for i in range(len(lists)):
                if not lists[i]:
                    continue
                if minNodeIdx == -1 or lists[i].val < lists[minNodeIdx].val:
                    minNodeIdx = i
            if minNodeIdx == -1:
                break
            else:
                tailNode.next = lists[minNodeIdx]
                tailNode = tailNode.next
                lists[minNodeIdx] = lists[minNodeIdx].next
        return dummyNode.next

            


    
        