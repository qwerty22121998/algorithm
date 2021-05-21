package main

import "fmt"

func larrysArray(A []int) string {
	cnt := 0

	for i := range A {
		for j := 0; j < i; j++ {
			if A[j] > A[i] {
				cnt++
			}
		}
	}

	if cnt%2 == 0 {
		return "YES"
	}
	return "NO"

}

func solve() {
	n := 0
	fmt.Scan(&n)
	arr := make([]int, n)
	for i := range arr {
		fmt.Scan(&arr[i])
	}
	fmt.Println(larrysArray(arr))

}

func main() {
	t := 0
	fmt.Scan(&t)

	for t > 0 {
		t--
		solve()
	}

}
