package uglynumberiii

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func TestUglyNumberIII(t *testing.T) {
	assert.Equal(t, 4, nthUglyNumber(3, 2, 3, 5))
	assert.Equal(t, 6, nthUglyNumber(4, 2, 3, 4))
	assert.Equal(t, 10, nthUglyNumber(5, 2, 11, 13))
	assert.Equal(t, 8, nthUglyNumber(5, 2, 3, 3))
	assert.Equal(t, 1999999984, nthUglyNumber(1000000000, 2, 217983653, 336916467))
}
