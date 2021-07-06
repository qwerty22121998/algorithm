// https://leetcode.com/problems/find-xor-sum-of-all-pairs-bitwise-and/ - HARD

package xorsum

func xorArr(arr []int) int {
	x := 0
	for _, v := range arr {
		x ^= v
	}
	return x
}

func getXORSum(arr1 []int, arr2 []int) int {
	return xorArr(arr1) & xorArr(arr2)
}
