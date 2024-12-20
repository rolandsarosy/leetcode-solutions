// https://leetcode.com/problems/contains-duplicate/

// Optimized solution - O(n) where n is the size of the input 
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        return unordered_set<int>(nums.begin(), nums.end()).size() < nums.size();
    }
};

// Bruteforce solution for practice - should be O(n^2)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
       for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] == nums[j]) {
                    return true;
                }
            }
       }
       return false;
    }
};
