//https://leetcode.com/problems/sum-root-to-leaf-numbers/
// Medium
package binary_tree

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
