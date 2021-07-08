package longest_sub_str

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func TestLongest(t *testing.T) {
	assert.Equal(t, 3, lengthOfLongestSubstring("abcabcbb"))
	assert.Equal(t, 1, lengthOfLongestSubstring("bbbbb"))
	assert.Equal(t, 3, lengthOfLongestSubstring("pwwkew"))
	assert.Equal(t, 0, lengthOfLongestSubstring(""))
}
