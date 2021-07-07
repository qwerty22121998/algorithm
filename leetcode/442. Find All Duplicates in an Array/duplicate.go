// https://leetcode.com/problems/find-all-duplicates-in-an-array/ - MEDIUM

package main

func intAbs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}

func findDuplicates(arr []int) []int {
	res := make([]int, 0)
	for _, v := range arr {
		pos := intAbs(v) - 1
		if arr[pos] < 0 {
			res = append(res, pos+1)
		}
		arr[pos] *= -1
	}
	return res
}
