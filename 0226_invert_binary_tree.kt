// https://leetcode.com/problems/invert-binary-tree/description/
// O(n) space and time complexity using a DFS search and recursion. 
/**
 * Example:
 * var ti = TreeNode(5)
 * var v = ti.`val`
 * Definition for a binary tree node.
 * class TreeNode(var `val`: Int) {
 *     var left: TreeNode? = null
 *     var right: TreeNode? = null
 * }
 */
class Solution {
    fun invertTree(root: TreeNode?): TreeNode? {
        if (root == null) return null

        var tempNode = root.left
        root.left = root.right
        root.right = tempNode

        invertTree(root.left)
        invertTree(root.right)

        return root
    }
}

// iterative BFS solution using a stack. Comes with an O(n) space and time complexity.
class Solution {
    fun invertTree(root: TreeNode?): TreeNode? {
        if (root == null) return null

        val stack = ArrayDeque<TreeNode>()
        stack.addFirst(root)

        while (stack.isNotEmpty()) {
            val element: TreeNode = stack.first();
            stack.removeFirst();

            val temp = element.left
            element.left = element.right
            element.right = temp

            if (element.left != null) stack.add(element.left)
            if (element.right != null) stack.add(element.right)
        }

        return root
    }
}
