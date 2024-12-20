// https://leetcode.com/problems/valid-anagram/

// Sorting solution. Should be O(nLogn + mLogm) where n is the length of input s and m is the length of input t. It's log because the built-in sorting algorithm works on a logarithmic scale too. 
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s == t;
    }
};

// HasMap solution. Luckily, C++ 20 unordered_set comparison is structural and not referential, meaning that this should be O(n+m)
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;

        unordered_map<char, int> sMap;
        unordered_map<char, int> tMap; 

        for (int i = 0; i < s.length(); i++) {
            sMap[s[i]]++;
            tMap[t[i]]++;
        }

        return sMap == tMap;
    }
};
