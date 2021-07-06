package last_k_prod

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func TestLastKProd(t *testing.T) {
	productOfNumbers := Constructor()
	productOfNumbers.Add(3)                             // [3]
	productOfNumbers.Add(0)                             // [3,0]
	productOfNumbers.Add(2)                             // [3,0,2]
	productOfNumbers.Add(5)                             // [3,0,2,5]
	productOfNumbers.Add(4)                             // [3,0,2,5,4]
	assert.Equal(t, 20, productOfNumbers.GetProduct(2)) // return 20. The product of the last 2 numbers is 5 * 4 = 20
	assert.Equal(t, 40, productOfNumbers.GetProduct(3)) // return 40. The product of the last 3 numbers is 2 * 5 * 4 = 40
	assert.Equal(t, 0, productOfNumbers.GetProduct(4))  // return 0. The product of the last 4 numbers is 0 * 2 * 5 * 4 = 0
	productOfNumbers.Add(8)                             // [3,0,2,5,4,8]
	assert.Equal(t, 32, productOfNumbers.GetProduct(2)) // return 32. The product of the last 2 numbers is 4 * 8 = 32
}

func TestLastKProd2(t *testing.T) {
	productOfNumbers := Constructor()
	productOfNumbers.Add(1)
	assert.Equal(t, 1, productOfNumbers.GetProduct(1))
	assert.Equal(t, 1, productOfNumbers.GetProduct(1))
	assert.Equal(t, 1, productOfNumbers.GetProduct(1))
	productOfNumbers.Add(7)
	productOfNumbers.Add(6)
	productOfNumbers.Add(7)
}
