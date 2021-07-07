package subarr_equal_k

import (
	"testing"

	"gopkg.in/go-playground/assert.v1"
)

func TestSubArraySum(t *testing.T) {
	assert.Equal(t, 2, subarraySum([]int{1, 1, 1}, 2))
	assert.Equal(t, 2, subarraySum([]int{1, 2, 3}, 3))
}
