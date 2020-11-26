package trie

type Trie struct {
	next map[rune]*Trie
	cnt  int
	end  int
}

/** Initialize your data structure here. */
func Constructor() Trie {
	return Trie{
		next: make(map[rune]*Trie),
	}
}

/** Inserts a word into the trie. */
func (this *Trie) Insert(word string) {
	root := this
	for _, r := range word {
		root.cnt++
		if root.next[r] == nil {
			newNode := Constructor()
			root.next[r] = &newNode
		}
		root = root.next[r]
	}
	root.cnt++
	root.end++
}

/** Returns if the word is in the trie. */
func (this *Trie) Search(word string) bool {
	root := this
	for _, r := range word {
		if root.next[r] == nil {
			return false
		}
		root = root.next[r]
	}
	return root.end > 0
}

/** Returns if there is any word in the trie that starts with the given prefix. */
func (this *Trie) StartsWith(prefix string) bool {
	root := this
	for _, r := range prefix {
		if root.next[r] == nil {
			return false
		}
		root = root.next[r]
	}
	return root.cnt > 0
}
