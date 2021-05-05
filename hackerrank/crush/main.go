package main

import (
	"fmt"
	"sort"
)

func allKeys(mp map[int]int) []int {
	keys := make([]int, 0)
	idx := 0
	for k := range mp {
		keys = append(keys, k)
		idx++
	}
	sort.Ints(keys)
	return keys
}

func crush(mp map[int]int) {
	keys := allKeys(mp)
	res := 0
	now := 0
	for _, v := range keys {
		now += mp[v]
		if now > res {
			res = now
		}
	}

	fmt.Println(res)
}

func main() {
	var n, m int
	fmt.Scanf("%d%d", &n, &m)
	a := make(map[int]int)
	for m > 0 {
		m--
		var i, j, k int
		fmt.Scanf("%d%d%d", &i, &j, &k)
		a[i] += k
		a[j+1] -= k
	}
	crush(a)
}
