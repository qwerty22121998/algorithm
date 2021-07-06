//https://leetcode.com/problems/ugly-number-iii/ - MEDIUM

package uglynumberiii

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func lcm(a, b int) int {
	return a * b / gcd(a, b)
}

func pos(x, a, b, c int) int {
	return x/a + x/b + x/c - (x/lcm(a, b) + x/lcm(a, c) + x/lcm(b, c)) + x/lcm(a, lcm(b, c))

}

func nthUglyNumber(n int, a int, b int, c int) int {
	l := 0
	h := int(2e18)
	for l <= h {
		m := (l + h) / 2
		if pos(m, a, b, c) >= n {
			h = m - 1
		} else {
			l = m + 1
		}
	}
	return l
}
