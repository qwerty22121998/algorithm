//https://www.hackerrank.com/challenges/max-array-sum/problem
//Medium
package main

import "fmt"

func max(arr ...int) int {
	res := arr[0]
	for _, v := range arr {
		if v > res {
			res = v
		}
	}
	return res
}

func maxSubsetSum(arr []int) int {
	n := len(arr)
	f := make([]int, n)
	f[0] = max(arr[0], 0)
	if n > 1 {
		f[1] = max(arr[0], arr[1], 0)
	}
	for i := 2; i < n; i++ {
		f[i] = max(f[i], f[i-1], f[i-2], f[i-2]+arr[i])
	}
	return f[n-1]
}

func main() {
	var n int
	fmt.Scan(&n)
	arr := make([]int, n)
	for i := range arr {
		fmt.Scan(&arr[i])
	}

	fmt.Println(maxSubsetSum(arr))
}
