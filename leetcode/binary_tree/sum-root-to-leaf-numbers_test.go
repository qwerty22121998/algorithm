package binary_tree

import "testing"

import "github.com/stretchr/testify/assert"

func Test_sumNumbers_1(t *testing.T) {
	root := N(1, N(2), N(3))
	assert.Equal(t, 12+13, sumNumbers(root))
}

func Test_sumNumbers_2(t *testing.T) {
	root := N(4, N(9, N(5), N(1)), N(0))
	assert.Equal(t, 495 + 491 + 40, sumNumbers(root))
}
