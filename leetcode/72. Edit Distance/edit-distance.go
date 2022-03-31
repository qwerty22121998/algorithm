package edit_distance

func min(a ...int) int {
	res := a[0]
	for _, v := range a[1:] {
		if res > v {
			res = v
		}
	}
	return res
}

func minDistance(word1 string, word2 string) int {
	d := make([][]int, len(word1)+1)
	for i := range d {
		d[i] = make([]int, len(word2)+1)
	}
	for i := 0; i <= len(word1); i++ {
		d[i][0] = i
	}
	for i := 0; i <= len(word2); i++ {
		d[0][i] = i
	}
	for i := 1; i <= len(word1); i++ {
		for j := 1; j <= len(word2); j++ {
			now := 1
			if word1[i-1] == word2[j-1] {
				now = 0
			}
			d[i][j] = min(d[i-1][j]+1, d[i][j-1]+1, d[i-1][j-1]+now)

		}
	}
	return d[len(word1)][len(word2)]
}
