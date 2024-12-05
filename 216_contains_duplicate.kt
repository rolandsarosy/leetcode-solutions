// https://leetcode.com/problems/contains-duplicate/

// Brute force solution.
class Solution {
    fun containsDuplicate(nums: IntArray): Boolean {
        for (i in nums) {
            var iCount = 1
            for (y in nums) {
                if (y == i)  iCount++
            }
            if (iCount > 2) return true
        }
        return false
    }
}
