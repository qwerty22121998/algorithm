package longest_sub_str

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func lengthOfLongestSubstring(str string) int {
	s := []rune(str)
	mp := make(map[rune]int)
	l := 0
	res := 0
	for r, v := range s {
		for l <= r && mp[v] > 0 {
			mp[s[l]]--
			l++
		}
		mp[v]++
		res = max(res, r-l+1)
	}
	return res
}
