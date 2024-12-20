// https://leetcode.com/problems/remove-outermost-parentheses/description/

// O(n) solution using a stack. Technically it is O(n+n) solution, or more specifically O(n+m) where n the input string, m is the output string. But we are assuming the worst case where the input is the same as the ouput, so m = n, meaning O(n+n) or O(2n), but we are dropping the constants so O(n).... goddamn
class Solution {
public:
    string removeOuterParentheses(string s) {
        deque<char> stack;
        int openerCount = 0;
        int closerCount = 0;

        for (int i = 0; i < s.size(); i++) {
            char currentElement = s[i];
            
            if (openerCount == 0 && closerCount == 0) {
                stack.push_front(currentElement);
                openerCount++;
                continue;
            }
            
            if (currentElement == '(') {
                stack.push_back(currentElement);
                openerCount++;
            } else {
                stack.push_back(currentElement);
                closerCount++;
            }

            if (openerCount == closerCount) {
                stack.pop_front();
                stack.pop_back();
                openerCount = 0;
                closerCount = 0;
            }
        }

        return std::string(stack.begin(), stack.end());
    }
};
