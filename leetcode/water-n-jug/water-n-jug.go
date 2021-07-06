// https://leetcode.com/problems/water-and-jug-problem/ - MEDIUM

package waternjug

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func canMeasureWater(jug1Capacity int, jug2Capacity int, targetCapacity int) bool {
	if targetCapacity > jug1Capacity+jug2Capacity {
		return false
	}

	return targetCapacity%gcd(jug1Capacity, jug2Capacity) == 0
}
