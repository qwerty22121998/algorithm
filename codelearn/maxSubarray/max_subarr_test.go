package maxsubarray

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func TestMaxSubarr(t *testing.T) {
	assert.Equal(t, 13, maxSubarray([]int{-1, 7, -2, 3, 4, 0, 1, -1}))
	assert.Equal(t, 0, maxSubarray([]int{-1, -2, -5, -1}))
}
