// https://leetcode.com/problems/linked-list-cycle/description/
// O(n) space and time complexity.
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
    fun hasCycle(head: ListNode?): Boolean {
        val historyMap = hashMapOf<ListNode, ListNode>() // Key: Head; Value: Next
        var ptr = head
        
        while (ptr != null && ptr.next != null) { 
            if (historyMap[ptr] == ptr.next) {
                return true
            } else {
                historyMap.put(ptr, ptr.next)
                ptr = ptr.next
            }
        }

        return false;
    }
}
