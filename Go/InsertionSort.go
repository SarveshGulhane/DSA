package main

import (
	"fmt"
)

func insertionSort(arr []int) {
	n := len(arr)
	for i := 0; i < n-1; i++ {
		key := arr[i]
		j := i - 1

		for j >= 0 && arr[j] > key {
			arr[j+1] = arr[j]
			j = j - 1
		}
		arr[j+1] = key
	}

}

func printSorted(arr []int) {
	for i := 0; i < len(arr); i++ {
		fmt.Printf("%d\t", arr[i])
	}
	fmt.Println()
}

func main() {
	arr := []int{12, 53, 25, 6, 24, 13}
	insertionSort(arr)
	printSorted(arr)
}
