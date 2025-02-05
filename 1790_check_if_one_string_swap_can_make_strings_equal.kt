// https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/description
// O(n) time complexity with O(1) space complexity.
class Solution {
    fun areAlmostEqual(s1: String, s2: String): Boolean {
        if (s1 == s2) return true

        val mismatches = mutableListOf<Pair<Char, Char>>()

        for (i in s1.indices) {
            if (s1[i] != s2[i]) {
                mismatches.add(Pair(s1[i], s2[i]))
                if (mismatches.size > 2) return false
            }
        }

        return mismatches.size == 2 && mismatches[0].first == mismatches[1].second && mismatches[0].second == mismatches[1].first
    }
}
