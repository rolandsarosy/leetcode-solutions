// https://neetcode.io/problems/merge-two-sorted-linked-lists

// Iterative solution. Constant space complexity and O(n+m) time complexity, where n & m are the sizes of the input lists.
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
    fun mergeTwoLists(list1: ListNode?, list2: ListNode?): ListNode? {
        val dummyHead = ListNode(Int.MIN_VALUE)
        var tail: ListNode? = dummyHead

        var pointer1 = list1
        var pointer2 = list2

        while (pointer1 != null && pointer2 != null) {
            if (pointer1.`val` < pointer2.`val`) {
                tail?.next = pointer1
                pointer1 = pointer1.next
            } else {
                tail?.next = pointer2
                pointer2 = pointer2.next
            }

            tail = tail?.next
        }

        tail?.next = pointer1 ?: pointer2
        return dummyHead.next
    }
}
