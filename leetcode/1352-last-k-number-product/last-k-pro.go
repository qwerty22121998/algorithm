package last_k_prod

type ProductOfNumbers struct {
	prod []int
}

func Constructor() ProductOfNumbers {
	return ProductOfNumbers{
		prod: []int{1},
	}
}

func (this *ProductOfNumbers) last() int {
	if len(this.prod) == 0 {
		return 1
	}
	return this.prod[len(this.prod)-1]
}

func (this *ProductOfNumbers) Add(num int) {
	if num == 0 {
		this.prod = []int{1}
		return
	}
	this.prod = append(this.prod, this.last()*num)
}

func (this *ProductOfNumbers) GetProduct(k int) int {
	l := len(this.prod)
	if l == 0 {
		return 0
	}
	pos := l - k - 1
	if pos < 0 {
		return 0
	}

	return this.last() / this.prod[pos]
}

/**
* Your ProductOfNumbers object will be instantiated and called as such:
* obj := Constructor();
* obj.Add(num);
* param_2 := obj.GetProduct(k);
 */
