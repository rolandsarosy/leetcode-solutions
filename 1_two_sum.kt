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

// O(n) solution. :) 
class Solution {
    fun twoSum(nums: IntArray, target: Int): IntArray {
        val traversalMap = mutableMapOf<Int, Int>() // Key: Number; Value: Index

        for (i in nums.indices) {
            if (traversalMap[target - nums[i]] != null) {
                return intArrayOf(i, traversalMap[target - nums[i]]!!) // If memory complexity wasn't an issue this wouldn't be here as a separate variable can be tested outside of the if statement and the compiler would know this is a non-null at this point.
            } else {
                traversalMap.put(nums[i], i)
            }
        }

        throw IllegalStateException("Invalid state, shouldn't have been reachable.")
    }
}
