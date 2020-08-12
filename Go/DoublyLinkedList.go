package main

import "fmt"

type node struct {
	val  int
	next *node
	prev *node
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
		temp.prev = nil
		head = temp
		return head
	}

	nnode := new(node)
	head.next = nnode
	nnode.val = inval
	nnode.prev = head
	return head
}

func (temp *node) addStart(inval int) *node {
	if head == nil {
		temp.val = inval
		temp.next = nil
		temp.prev = nil
		head = temp
		return head
	}

	nnode := new(node)
	nnode.next = head
	head.prev = nnode
	nnode.val = inval
	head = nnode
	return head
}

func (temp *node) deleteEnd() *node {
	if head == nil {
		fmt.Println("No linked-list found")
		return head
	}

	temp = head
	for temp.next != nil {
		temp = temp.next
	}
	temp = temp.prev
	temp.next.prev = nil
	temp.next = nil
	return head
}

func (temp *node) deleteStart() *node {
	if head == nil {
		fmt.Println("No linked-list found")
		return head
	}

	temp = head
	head = head.next
	head.prev = nil
	temp.next = nil
	return head
}

func main() {
	list := new(node)
	list.addEnd(13)
	list.addEnd(35)
	list.addStart(64)
	list.display(head)
	list.deleteEnd()
	list.deleteStart()
	list.display(head)
}
