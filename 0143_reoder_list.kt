// https://leetcode.com/problems/reorder-list/
// O(n) space and time complexity solution using a reverse stack of linked list
/**
 * Example:
 * var li = ListNode(5)
 * var v = li.`val`
 * Definition for singly-linked list.
 * class ListNode(var `val`: Int) {
 *     var next: ListNode? = null
 * }
 */
class Solution {
    fun reorderList(head: ListNode?): Unit {
        val reverseStack = ArrayDeque<ListNode>()
        var linkCount = 0
       
        var ptr = head
        while (ptr != null) {
            reverseStack.addFirst(ptr)
            linkCount = linkCount + 1

            ptr = ptr.next
        }
        
        ptr = head
        while (linkCount > 0) {
            val tempNode = ptr?.next
            ptr?.next = reverseStack.first()
            ptr?.next?.next = tempNode

            ptr = ptr?.next?.next
            linkCount = linkCount - 2
            reverseStack.removeFirst()
        }

        ptr?.next = null
    }
}
