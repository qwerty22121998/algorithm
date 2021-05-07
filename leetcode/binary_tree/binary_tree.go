package binary_tree

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func N(val int,c ...*TreeNode) *TreeNode {
	node := &TreeNode{
		Val:   val,
	}
	if len(c) > 0 {
		node.Left = c[0]
	}
	if len(c) > 1 {
		node.Right = c[1]
	}

	return node
}
