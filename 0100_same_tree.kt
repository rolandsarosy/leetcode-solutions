// https://leetcode.com/problems/same-tree/description/
// Time complexity: O(min(p, q)) where p and q are the amount of nodes in the respective trees. Best case should be O(n)
// Space complexity: O(max(heightP, heightQ)) where the variables are the heights of their respective trees. Best case is O(logN) for a balanced tree. 
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
    fun isSameTree(p: TreeNode?, q: TreeNode?): Boolean {
        if (p == null && q == null) return true;
        if (p == null || q == null) return false;

        return p.`val` == q.`val` && isSameTree(p.left, q.left) && isSameTree(p.right, q.right)
    }
}
