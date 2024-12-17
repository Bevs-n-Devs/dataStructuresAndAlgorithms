package main

import "fmt"

/*
Node object for a linked list
*/
type Node struct {
	val  int32
	next *Node
}

/*
Method to print all nodes in the linked list
*/
func (n *Node) print() {
	fmt.Printf("%v", n.val)
	nxt := n.next

	// When next is a nullptr, we have
	// reached the end of the linked list
	// and this loop will stop
	// NOTE : Go does not contain "while" loops
	for {
		if nxt == nil {
			break
		}
		fmt.Printf("->%v", nxt.val)
		nxt = nxt.next
	}

	fmt.Println("->NULL")
}

/*
Reverses a Linked List

@param n: 1rst node of linked list
@type n: Node

@return The 1rst node of the reversed linked list
*/
func reverse_llist(n *Node) *Node {
	var prev *Node
	curr := n
	next := n.next
	for {
		if next == nil {
			break
		}
		curr.next = prev
		prev = curr
		curr = next
		next = next.next
	}

	curr.next = prev
	return curr
}

func main() {
	fmt.Println("Will attempt to reverse the following Linked List:")
	var llist *Node = &Node{1, nil}
	llist.next = &Node{2, nil}
	llist.next.next = &Node{3, nil}
	llist.next.next.next = &Node{4, nil}
	llist.next.next.next.next = &Node{5, nil}
	llist.print()
	llist = reverse_llist(llist)
	fmt.Println("Linked List after reversal:")
	llist.print()
}
