// https://leetcode.com/problems/two-sum/description/

// O(n^2) solution, because we need to traverse twice
class Solution {
    fun twoSum(nums: IntArray, target: Int): IntArray {
        for (i in nums.indices) {
            val requiredPair = target - nums[i]
            
            for (j in (i + 1) until nums.size) {
                if (nums[j] == requiredPair) return intArrayOf(i, j)
            }
        }

        throw IllegalStateException("Invalid state, shouldn't have been reachable.")
    }
}
