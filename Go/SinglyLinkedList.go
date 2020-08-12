package main

import "fmt"

type node struct {
	val  int
	next *node
}

var head *node = nil

func (temp *node) display(head *node) *node {
	fmt.Print("List: ")
	for head != nil {
		fmt.Printf("%d ", head.val)
		head = head.next
	}
	fmt.Println()
	return head
}

func (temp *node) addEnd(inval int) *node {
	if head == nil {
		temp.val = inval
		temp.next = nil
		head = temp
		return head
	}

	temp = head
	for temp.next != nil {
		temp = temp.next
	}
	var nnode *node = new(node)
	temp.next = nnode
	nnode.val = inval
	nnode.next = nil
	return head
}

func (temp *node) addStart(inval int) *node {
	if head == nil {
		temp.val = inval
		temp.next = nil
		head = temp
		return head
	}
	nnode := new(node)
	nnode.val = inval
	nnode.next = head
	head = nnode
	return head
}

func (temp *node) deleteEnd() *node {
	if head == nil {
		fmt.Println("NO linked-list found")
		return head
	}

	t := new(node)
	temp = head
	for temp.next != nil {
		t = temp
		temp = temp.next
	}

	t.next = nil
	return head
}

func (temp *node) deleteStart() *node {
	if head == nil {
		fmt.Println("NO linked-list found")
		return head
	}

	temp = head
	head = head.next
	temp.next = nil
	return head
}

func main() {
	list := new(node)
	list.deleteStart()
	list.addEnd(15)
	list.addEnd(4)
	list.addStart(61)
	list.addEnd(23)
	list.addStart(8)
	list.display(head)
	list.deleteEnd()
	list.deleteStart()
	list.display(head)
}
