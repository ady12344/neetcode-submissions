class Node:
    def __init__(self , val: int ):
        self.val = val
        self.next = None
        self.prev = None
    
class Deque:
    
    def __init__(self):
        self.dummyhead = Node(-1)
        self.dummytail = Node(-1)
        self.dummyhead.next = self.dummytail
        self.dummytail.prev = self.dummyhead

    def isEmpty(self) -> bool:
        return self.dummyhead.next == self.dummytail
        

    def append(self, value: int) -> None:
        node = Node(value)
        prevNode = self.dummytail.prev
        node.next = prevNode.next
        node.prev = prevNode
        self.dummytail.prev = node
        prevNode.next = node

        

    def appendleft(self, value: int) -> None:
        node = Node(value)
        nextNode = self.dummyhead.next
        node.next = nextNode
        node.prev = self.dummyhead
        nextNode.prev = node
        self.dummyhead.next = node
        

    def pop(self) -> int:
        if(self.isEmpty()): return -1
        nodePrev = self.dummytail.prev
        valueToReturn = nodePrev.val
        nodePrev.prev.next = self.dummytail
        self.dummytail.prev = nodePrev.prev
        return valueToReturn

    def popleft(self) -> int:
        if(self.isEmpty()): return -1
        nextNode = self.dummyhead.next
        valueToReturn = nextNode.val
        self.dummyhead.next = nextNode.next
        nextNode.next.prev = self.dummyhead
        return valueToReturn
