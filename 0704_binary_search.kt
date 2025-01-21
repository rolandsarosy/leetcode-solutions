// https://leetcode.com/problems/binary-search/description/
// O(logn) solution with constant (O(1)) space complexity
class Solution {
    fun search(nums: IntArray, target: Int): Int {
        var left = 0;
        var right = nums.size -1
        
        while (left < right) {
            var center = (left + right) / 2

            if (nums[center] < target) {
                left = center + 1
            } else if (nums[center] > target) {
                right = center - 1
            } else {
                return center
            }
        }

        return -1
    }
}
