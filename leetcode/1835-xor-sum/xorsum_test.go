package xorsum

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func TestXorSum(t *testing.T) {
	assert.Equal(t, 0, getXORSum([]int{1, 2, 3}, []int{6, 5}))
	assert.Equal(t, 4, getXORSum([]int{12}, []int{4}))
}
