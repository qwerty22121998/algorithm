// https://leetcode.com/explore/interview/card/top-interview-questions-hard/116/array-and-strings/829/ - MEDIUM
package sum

func fourSumCount(nums1 []int, nums2 []int, nums3 []int, nums4 []int) int {
	mp := make(map[int]int)
	for _, a := range nums1 {
		for _, b := range nums2 {
			mp[a+b]++
		}
	}
	res := 0
	for _, c := range nums3 {
		for _, d := range nums4 {
			res += mp[-(c + d)]
		}
	}
	return res
}
