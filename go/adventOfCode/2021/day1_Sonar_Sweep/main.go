package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	r, err := readInput("./input.txt")
	if err != nil {
		fmt.Println(err)
	}
	s := slidingMeasture(r)
	c := countIncrease(s)
	fmt.Println(c)
}

func readInput(filePath string) ([]int, error) {
	var inputs []int
	var i int
	f, err := os.Open(filePath)
	if err != nil {
		return nil, err
	}
	defer f.Close()

	scanner := bufio.NewScanner(f)

	for scanner.Scan() {
		i, _ = strconv.Atoi(scanner.Text())
		inputs = append(inputs, i)
	}
	return inputs, nil

}

func countIncrease(inputs []int) int {
	var prev, cur, increaseCount int
	prev, cur = 0, 1
	for ; cur < len(inputs) ;  {
		if inputs[cur] > inputs[prev] {
			increaseCount++
		}
		 prev = cur
		 cur += 1
	}
	return increaseCount
}

func slidingMeasture(inputs []int) []int {
	var outputs []int
	var slideHead int
	slideHead = 0
	for ; slideHead + 2 < len(inputs) ; slideHead++ {
		outputs = append(outputs, inputs[slideHead] + inputs[slideHead+1] + inputs[slideHead+2])
	}
	return outputs
}