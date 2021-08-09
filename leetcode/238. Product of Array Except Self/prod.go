package prod

func productExceptSelf(arr []int) []int {
	n := len(arr)
	res := make([]int, n)
	res[0] = arr[0]
	for i := 1; i < n; i++ {
		res[i] = res[i-1] * arr[i]
	}
	now := 1

	for i := n - 1; i >= 1; i-- {
		res[i] = res[i-1] * now
		now *= arr[i]
	}
	res[0] = now

	return res
}
