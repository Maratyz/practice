package main

import "fmt"

func main() {
	slice1 := []int{5,4,3,2,1}
	slice2 := []int{8,9,10,7,6}
	slice3 := []int{1,1,1,3,2}
	fmt.Println(QuickSort(slice1))
	fmt.Println(QuickSort(slice2))
	fmt.Println(QuickSort(slice3))
}

func QuickSort( nums []int) []int {
	if len(nums) < 2 {
		return nums
	}
	pivot := nums[0]
	var l, r []int

	for i := 1 ; i < len(nums) ; i++ {
		if nums[i] <= pivot {
			l = append(l, nums[i])
		}
		if nums[i] > pivot {
			r = append(r, nums[i])
		}
	}
	sorted := append(QuickSort(l), pivot)
	sorted = append(sorted, QuickSort(r)...)

	return sorted
}