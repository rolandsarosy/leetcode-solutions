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
