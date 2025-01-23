// https://leetcode.com/problems/maximum-depth-of-binary-tree/
// O(n) space and time complexity. We weren't able to assume that the input tree is perfect, balanced or a search tree and thus we cannot skip the part where we navigate through each branch until we reach each leaf.
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
    fun maxDepth(root: TreeNode?): Int {
        if (root == null) {
            return 0 // Base case: if the tree is empty, depth is 0
        }

        // Recursively calculate the depth of the left and right subtrees
        val leftDepth = maxDepth(root.left)
        val rightDepth = maxDepth(root.right)

        // Return the maximum of the two depths, plus 1 for the current node
        return maxOf(leftDepth, rightDepth) + 1
    }
}
