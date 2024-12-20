// https://leetcode.com/problems/valid-palindrome/

// O(n) solution
class Solution {
public:
    bool isPalindrome(string s) { 
        int left = 0;
        int right = s.size() - 1;

        while (right - left >= 1) {
            char leftPosition = tolower(s[left]);
            char rightPosition = tolower(s[right]);

            if (!iswalnum(leftPosition)) {
                left++;
                continue;
            }

            if (!iswalnum(rightPosition)) {
                right--;
                continue;
            }

            if (leftPosition != rightPosition) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};
