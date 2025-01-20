// https://leetcode.com/problems/reverse-string/

// O(n) time complexity with an O(1) space complexity, as per the requirements
class Solution {
    fun reverseString(s: CharArray): Unit {
        var first = 0
        var last = s.lastIndex

        while (first < last) {
            val temp = s[first]

            s[first] = s[last]
            s[last] = temp

            first = first + 1
            last = last - 1
        }
    }
}
