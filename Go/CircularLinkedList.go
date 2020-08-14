package main

import "fmt"

type node struct {
	val  int
	next *node
}

var head *node = nil

func (temp *node) display(head *node) *node {
	fmt.Print("List: ")
	temp = head
	for temp.next != head {
		fmt.Printf("%d ", temp.val)
		temp = temp.next
	}
	fmt.Printf("%d ", temp.val)
	fmt.Println()
	return head
}

func (temp *node) addEnd(inval int) *node {
	if head == nil {
		temp.val = inval
		temp.next = nil
		head = temp
		head.next = head
		return head
	}

	temp = head
	for temp.next != head {
		temp = temp.next
	}
	nnode := new(node)
	temp.next = nnode
	nnode.val = inval
	nnode.next = head
	return head
}

func (temp *node) addStart(inval int) *node {
	if head == nil {
		temp.val = inval
		temp.next = nil
		head = temp
		head.next = head
		return head
	}

	nnode := new(node)
	nnode.next = head
	nnode.val = inval
	temp = head
	for temp.next != head {
		temp = temp.next
	}
	temp.next = nnode
	head = nnode
	return head
}

func (temp *node) deleteEnd() *node {
	if head == nil {
		fmt.Println("No linked-list found")
	}

	t := new(node)
	temp = head
	for temp.next != head {
		t = temp
		temp = temp.next
	}
	t.next = head
	return head
}

func (temp *node) deleteStart() *node {
	if head == nil {
		fmt.Println("No linked-list found")
	}

	temp = head
	for temp.next != head {
		temp = temp.next
	}
	head = head.next
	temp.next.next = nil
	temp.next = head
	return head
}

func main() {
	list := new(node)
	list.addEnd(13)
	list.addEnd(33)
	list.addStart(5)
	list.addStart(25)
	list.display(head)
	list.deleteEnd()
	list.deleteStart()
	list.display(head)
}
