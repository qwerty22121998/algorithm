package dup_num

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func TestDupNum(t *testing.T) {
	assert.Equal(t, 2, findDuplicate([]int{1, 3, 4, 2, 2}))
	assert.Equal(t, 3, findDuplicate([]int{3, 1, 3, 4, 2}))
	assert.Equal(t, 1, findDuplicate([]int{1, 1}))
	assert.Equal(t, 9, findDuplicate([]int{2, 5, 9, 6, 9, 3, 8, 9, 7, 1}))
}
