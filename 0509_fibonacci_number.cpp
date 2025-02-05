// https://leetcode.com/problems/fibonacci-number/ 
// O(2^n) time and O(n) space complexity. Very slow as it re-does the calculations again and again. The callstack tree essentially doubles with every call. 
class Solution {
public:
    int fib(int n, int[] memo = nullptr) {
        if (n == 0) {
            return 0;
        } else if (n == 1) {
            return 1;
        } else {
            return fib(n - 1) + fib(n - 2);
        }
    }
};

// memoized example will come below here
