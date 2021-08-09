//https://leetcode.com/explore/interview/card/top-interview-questions-hard/116/array-and-strings/828/ - MEDIUM
package spiral_matrix

type Direction struct {
	X int
	Y int
}

var Next = map[Direction]Direction{
	Right: Down,
	Down:  Left,
	Left:  Up,
	Up:    Right,
}

var Down = Direction{0, 1}
var Right = Direction{1, 0}
var Up = Direction{0, -1}
var Left = Direction{-1, 0}

func spiralOrder(matrix [][]int) []int {
	Y := len(matrix)
	X := len(matrix[0])

	res := make([]int, 0, Y*X)

	x, y := 0, 0

	dir := Right
	for len(res) != X*Y {
		res = append(res, matrix[y][x])
		matrix[y][x] = 6969
		nx, ny := x+dir.X, y+dir.Y

		if nx < 0 || nx == X || ny < 0 || ny == Y || matrix[ny][nx] == 6969 {
			dir = Next[dir]
			nx, ny = x+dir.X, y+dir.Y
		}
		x, y = nx, ny
	}
	return res
}
