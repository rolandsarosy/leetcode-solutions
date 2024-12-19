// https://leetcode.com/problems/baseball-game/description/

// O(n) stack solution
class Solution {
public:
    int calPoints(vector<string>& operations) {
        deque<int> stack;
        int points = 0;

        for (int i = 0; i < operations.size(); i++) {
            string current = operations[i];

            if (current == "+") {
                int newScore = stack.back() + stack[stack.size() - 2];
                points = points + newScore;
                stack.push_back(newScore);
            } else if (current == "D") {
                int newScore = stack.back() * 2;
                points = points + newScore;
                stack.push_back(newScore);
            } else if (current == "C") {
                int last = stack.back();
                points = points - last;
                stack.pop_back();
            } else {
                stack.push_back(stoi(current));
                points = points + stoi(current);
            }
        }

        return points;
    }
};

// O(n) stack solution with unmaintanable, unreadable code for bonus points.... it's faster tho.
class Solution {
public:
    int calPoints(vector<string>& operations) {
        deque<int> stack;
        int points = 0;

        for (int i = 0; i < operations.size(); i++) {
            if (operations[i] == "+") {
                points = points + (stack.back() + stack[stack.size() - 2]);
                stack.push_back(stack.back() + stack[stack.size() - 2]);
            } else if (operations[i] == "D") {
                points = points + stack.back() * 2;
                stack.push_back(stack.back() * 2);
            } else if (operations[i] == "C") {
                points = points - stack.back();
                stack.pop_back();
            } else {
                stack.push_back(stoi(operations[i]));
                points = points + stoi(operations[i]);
            }
        }

        return points;
    }
};
