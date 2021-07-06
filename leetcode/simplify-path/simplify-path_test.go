package simplifypath

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func TestSimplifyTest(t *testing.T) {
	assert.Equal(t, "/home", simplifyPath("/home/"))
	assert.Equal(t, "/", simplifyPath("/../"))
	assert.Equal(t, "/home/foo", simplifyPath("/home//foo/"))
	assert.Equal(t, "/c", simplifyPath("/a/./b/../../c/"))
}
