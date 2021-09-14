package maxsubarray

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func maxSubarray(a []int) int {

	f := make([]int, len(a))
	f[0] = a[0]
	res := f[0]
	for i := 1; i < len(a); i++ {
		f[i] = max(f[i-1]+a[i], a[i])
		res = max(res, f[i])
	}
	return max(res, 0)
}
