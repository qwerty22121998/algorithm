package sum

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func Test4SUM(t *testing.T) {
	assert.Equal(t, 2, fourSumCount([]int{1, 2}, []int{-2, -1}, []int{-1, 2}, []int{0, 2}))
	assert.Equal(t, 1, fourSumCount([]int{0}, []int{0}, []int{0}, []int{0}))
}
