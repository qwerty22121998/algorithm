package sum_root_to_leaf_numbers

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_sumNumbers_1(t *testing.T) {
	tree := &TreeNode{
		Val:   1,
		Left:  &TreeNode{
			Val:   2,
			Left:  nil,
			Right: nil,
		},
		Right: &TreeNode{
			Val:   3,
			Left:  nil,
			Right: nil,
		},
	}

	sum := sumNumbers(tree)
	assert.Equal(t, 12 + 13, sum)
}

func Test_sumNumbers_2(t *testing.T) {
	tree := &TreeNode{
		Val:   4,
		Left:  &TreeNode{
			Val:   9,
			Left:  &TreeNode{
				Val:   5,
				Left:  nil,
				Right: nil,
			},
			Right: &TreeNode{
				Val:   1,
				Left:  nil,
				Right: nil,
			},
		},
		Right: &TreeNode{
			Val:   0,
			Left:  nil,
			Right: nil,
		},
	}

	sum := sumNumbers(tree)
	assert.Equal(t, 495 + 491 + 40, sum)
}