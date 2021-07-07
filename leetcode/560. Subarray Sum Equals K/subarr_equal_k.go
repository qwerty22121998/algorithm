// https://leetcode.com/problems/subarray-sum-equals-k/submissions/ - MEDIUM
package subarr_equal_k

func subarraySum(a []int, k int) int {
	mp := make(map[int]int)
	mp[0] = 1
	sum := 0
	result := 0
	for _, v := range a {
		sum += v
		result += mp[sum-k]
		mp[sum]++
	}

	return result
}
