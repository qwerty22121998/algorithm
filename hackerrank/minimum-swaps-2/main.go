package main

import "fmt"

func minimumSwap(arr []int) {
	mp := make(map[int]int)
	rMp := make(map[int]int)

	for i, e := range arr {
		mp[e] = i
		rMp[i] = e
	}
	res := 0

	swp := func(i, j int) {
		a := rMp[i]
		b := rMp[j]
		mp[a] = j
		mp[b] = i
		rMp[i] = b
		rMp[j] = a

	}

	for i := 0; i < len(arr); i++ {
		// fmt.Println("value", i, "pos", mp[i])
		ori := mp[i]
		if ori == i {
			continue
		}
		res++
		// fmt.Println("swap", i, mp[i])
		swp(i, mp[i])

	}

	fmt.Println(res)

}

func main() {
	var n int
	fmt.Scanf("%d", &n)
	a := make([]int, n)
	for i := range a {
		fmt.Scanf("%d", &a[i])
		a[i]--
	}
	minimumSwap(a)
}
