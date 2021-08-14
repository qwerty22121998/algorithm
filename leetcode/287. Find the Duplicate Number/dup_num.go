// https://leetcode.com/explore/interview/card/top-interview-questions-hard/116/array-and-strings/834/- MEDIUM
package dup_num

func findDuplicate(arr []int) int {
	a := arr[0]
	b := arr[0]

	for {
		a = arr[arr[a]]
		b = arr[b]
		if a == b {
			break
		}
	}

	b = arr[0]

	for a != b {
		b = arr[b]
		a = arr[a]
	}
	return a
}
