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

// Interestingly, I thought this would work, but it does not. The reason for it is that for each recursive call, we're copying the contents of the vector. It simply runs out of memory on Leetcode.
// Space complexity: O(2^n)
class Solution {
public:
    int fib(int n, vector<int> memo = {}) {
        if (n == 0) return 0;
        if (n == 1) return 1;

        if (memo.empty()) {
            memo.resize(n + 1, -1);
        }

        if (memo[n] != -1) {
            return memo[n];
        } else {
            memo[n] = fib(n-1, memo) + fib(n-2, memo);
        }

        return memo[n];
    }
};

// Final solution. Function overloading with proper memoization. 
// O(n) time and space complexity.
class Solution {
public:
    int fib(int n) {
        vector<int> memo(n + 1, -1);
        return fib(n, memo);
    }

    int fib(int n, vector<int>& memo) {
        if (n == 0) return 0;
        if (n == 1) return 1;

        if (memo[n] != -1) {
            return memo[n];
        } else {
            memo[n] = fib(n-1, memo) + fib(n-2, memo);
        }

        return memo[n];
    }
};
