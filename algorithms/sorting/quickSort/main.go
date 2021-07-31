package main

import "fmt"

func main() {
	slice1 := []int{5,4,3,2,1}
	slice2 := []int{8,9,10,7,6}
	fmt.Println(QuickSort(slice1))
	fmt.Println(QuickSort(slice2))
}

func QuickSort( nums []int) []int {
	if len(nums) < 2 {
		return nums
	}
	pivot := nums[0]
	var l, r []int

	for i := 0 ; i < len(nums) ; i++ {
		if nums[i] < pivot {
			l = append(l, nums[i])
		}
		if nums[i] > pivot {
			r = append(r, nums[i])
		}
	}
	// go does not have [] + [] syntax, append pivot to the left slice before recursion
	l = append(l, pivot)

	return append(QuickSort(l), QuickSort(r)...)
}