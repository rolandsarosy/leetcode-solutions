// https://leetcode.com/problems/reverse-linked-list/description/

// O(n) solution with constant space complexity
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
    fun reverseList(head: ListNode?): ListNode? {
        var previousNode: ListNode? = null
        var currentNode: ListNode? = head
        var nextNode: ListNode? = null

        while (currentNode != null) {
            nextNode = currentNode.next
            currentNode.next = previousNode
            previousNode = currentNode
            currentNode = nextNode
        }
        return previousNode
    }
}

// O(n) solution where I reduced the variable scoping to make the problem actually a two-pointer problem. 
class Solution {
    fun reverseList(head: ListNode?): ListNode? {
        var previousNode: ListNode? = null
        var currentNode: ListNode? = head
        
        while (currentNode != null) {
            var nextNode = currentNode.next
            currentNode.next = previousNode
            previousNode = currentNode
            currentNode = nextNode
        }
        return previousNode
    }
}

// O(n) space and time complexity, but with a recursive approach
class Solution {
    fun reverseList(head: ListNode?, previous: ListNode? = null): ListNode? {
        if (head == null) {
            return previous
        }
        
        val nextHead = head.next
        head.next = previous
        return reverseList(nextHead, head)
    }
}
