// https://leetcode.com/problems/two-sum/

// Quick and dirty O(n^2) solution
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            int currentNum = nums[i];
            int targetNum = target - currentNum;
            
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] == targetNum) {
                    return {i, j};
                }
            }
        }
        
        throw invalid_argument("Function was supplied with invalid inputs as there always must be exactly one correct solution.");
    }
};


// O(n) solution. Lesson: It's hashmaps. It always is.
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> traversalMap; // Map: <value, index>

        for (int i = 0; i < nums.size(); i++) {
            int complementerValue = target - nums[i]; // We are looking for this value

            if (traversalMap.find(complementerValue) != traversalMap.end()) { // Lookup if map has key of COMPLEMENTER
                return {i, traversalMap[complementerValue]};
            } else {
                traversalMap[nums[i]] = i;
            }
        }
        
        throw invalid_argument("Invalid state, shouldn't have been reachable.");
    }
};
