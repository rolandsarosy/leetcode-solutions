// https://leetcode.com/problems/fibonacci-number/description/
// O(n) space and time complexity using memoization with a hashmap
class Solution {
    fun fib(n: Int, memo: MutableMap<Int, Int> = mutableMapOf()): Int { // key: fibonacci number, value: calculated sum for the specific fibonacci number
        if (n in memo) return memo[n]!!

        if (n == 0) return 0
        if (n == 1) return 1

        memo[n] = (fib(n - 1, memo) + fib(n - 2, memo))

        return memo[n]!!
    }
}
