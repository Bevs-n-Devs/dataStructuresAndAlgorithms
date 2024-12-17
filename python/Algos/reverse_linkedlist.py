class Node:
    """
    Node object for a linked list
    """
    def __init__(self, v: int):
        """
        Constructor for Linked List Node
        """
        self.val = v
        self.nxt = None

    def print(self):
        """
        Method to print all nodes in the linked list
        """
        print(f"{self.val}", end="")
        _next = self.nxt

        # when next is a nullptr, we have 
        # reached the end of the linked list
        # and this loop will stop
        while _next is not None:
            print(f"->{_next.val}", end="")
            _next = _next.nxt

        print("->NULL")

def reverse_llist(n: Node) -> Node:
    """
    Reverses a Linked List

    @param n: 1rst node of linked list
    @type n: Node

    @return The 1rst node of the reversed linked list 
    """

    prev = None
    curr = n
    _nxt = n.nxt

    # when next is a nullptr, we have 
    # reached the end of the linked list
    # and this loop will stop
    while _nxt is not None:
        curr.nxt = prev
        prev = curr
        curr = _nxt
        _nxt = _nxt.nxt

    curr.nxt = prev

    return curr


llist = Node(1)
llist.nxt = Node(2)
llist.nxt.nxt = Node(3)
llist.nxt.nxt.nxt = Node(4)
llist.nxt.nxt.nxt.nxt = Node(5)

if __name__ == "__main__":
    print("Will attempt to reverse the following Linked List:")
    llist.print()
    llist = reverse_llist(llist)
    print("Linked List after reversal:")
    llist.print()