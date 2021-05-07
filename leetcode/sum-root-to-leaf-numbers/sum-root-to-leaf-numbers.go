//https://leetcode.com/problems/sum-root-to-leaf-numbers/
// Medium
package sum_root_to_leaf_numbers

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func calc(node *TreeNode, memoize int, sum *int) {
	if node == nil {
		return
	}
	if node.Left == nil && node.Right == nil {
		*sum += memoize*10 + node.Val
	}
	calc(node.Left, memoize*10+node.Val, sum)
	calc(node.Right, memoize*10+node.Val, sum)

}

func sumNumbers(root *TreeNode) int {
	res := 0
	calc(root, 0, &res)
	return res
}
