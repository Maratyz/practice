package main

import "fmt"

func main()  {
	a, b := "let1 art can", "let2 own kit dig"
	listA, listB := stringToList(a), stringToList(b)
	fmt.Println(aLargerThanb(listA, listB))
	c, d := "ab2 off key dog","ab1 off key dog"
	listC, listD := stringToList(c), stringToList(d)
	fmt.Println(aLargerThanb(listC, listD))
	fmt.Println(logSort([]string{a,b,c,d}))
}

func logSort(logs []string) []string{
	if len(logs) < 2 {
		return logs
	}
	pivot := logs[0]
	var l, r []string
	for i := 1 ; i < len(logs) ; i++ {
		if aLargerThanb( stringToList(pivot), stringToList(logs[i]) ) {
			r = append(r, logs[i])
		} else {
			l = append(l, logs[i])
		}
	}
	r = append(r, pivot)
	return append(logSort(l), logSort(r)...)
}

func isDigitLog(d []string) bool {
	for _, v := range d[1] {
		if v >= '0' || v <= '9'	{
			return true
		}
	}
	return false
}

func aLargerThanb(a, b []string) bool {
	var identifierDiff bool
	var upper int
	if len(a) < len(b) {
		upper = len(a)
	} else {
		upper = len(b)
	}
	for i := 1 ; i < upper ; i++  {
		for j := 0 ; j < len(a[i]) ; j++ {
			if a[i][j] == b[i][j] {
				continue
			}
			if a[i][j] < b[i][j] {
				if i == 0 {
					identifierDiff = true
				}
				return true
			} else {
				if i == 0 {
					identifierDiff = false
				}
				return false
			}
		}
	}
	return identifierDiff
}

func stringToList(s string) []string {
	var buff []int32
	var list []string
	for k, v := range s {
		buff = append(buff, v)
		if  v == ' ' || k == len(s)-1 {
			list = append(list, string(buff))
			buff = []int32{}
		}
	}
	return list
}

