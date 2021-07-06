// https://leetcode.com/problems/simplify-path/ - MEDIUM

package simplifypath

import "strings"

type node struct {
	Path string
	Next *node
	Pre  *node
}

func simplifyPath(path string) string {
	paths := strings.Split(path, "/")

	root := &node{
		Path: "",
	}
	now := root

	for _, path := range paths {
		if path == "" || path == "." {
			continue
		}
		if path == ".." {
			if now == root {
				continue
			}

			now = now.Pre
			continue
		}
		newNode := &node{
			Path: path,
			Pre:  now,
		}
		now.Next = newNode
		now = newNode
	}

	paths = []string{}

	for root != now.Next {
		paths = append(paths, root.Path)
		root = root.Next
	}

	result := strings.Join(paths, "/")

	if result == "" {
		result = "/"
	}

	return result

}
