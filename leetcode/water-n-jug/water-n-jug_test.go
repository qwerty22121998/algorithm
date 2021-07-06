package waternjug

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func TestWaterNJug(t *testing.T) {
	assert.True(t, canMeasureWater(3, 5, 4))
	assert.False(t, canMeasureWater(2, 6, 5))
	assert.True(t, canMeasureWater(1, 2, 3))
}
