// https://leetcode.com/problems/valid-anagram/

// O(nLogn) solution, bruteforce
class Solution {
    fun isAnagram(s: String, t: String): Boolean {
        if (s.length != t.length) return false;

        return s.toCharArray().sorted().equals(t.toCharArray().sorted())
    }
}

// O(n+m) solution, where n is the length of s & m is the length of t
class Solution {
    fun isAnagram(s: String, t: String): Boolean {
        if (s.length != t.length) return false;

        val sHashMap : HashMap<Char, Int> = HashMap<Char, Int>()
        val tHashMap : HashMap<Char, Int> = HashMap<Char, Int>()

        // Can assume same length, only 1 loop is necessary.
        for (i in s.indices) {
            sHashMap[s[i]] = sHashMap.getOrDefault(s[i], 0) + 1
            tHashMap[t[i]] = tHashMap.getOrDefault(t[i], 0) + 1
        }

        return sHashMap == tHashMap // Apparently this checks for structural equality only, not referential. So it works. 
    }
}
