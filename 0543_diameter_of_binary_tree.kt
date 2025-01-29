// O(n) time and space complexity. Uses a DFS recursive function
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
    var maxDiameter = 0

    fun diameterOfBinaryTree(root: TreeNode?): Int {
        dfsTravel(root)

        return maxDiameter
    }

    fun dfsTravel(node: TreeNode?): Int {
        if (node == null) return 0

        val leftHeight = dfsTravel(node.left)
        val rightHeight = dfsTravel(node.right)
        val currentDiameter = leftHeight + rightHeight // Trick: The diameter of a node in a binary tree is the sum of their left and right height.

        maxDiameter = max(maxDiameter, currentDiameter)
        return 1 + max(leftHeight, rightHeight)
    }
}
