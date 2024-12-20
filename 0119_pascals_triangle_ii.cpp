// https://leetcode.com/problems/pascals-triangle-ii/

// Should be O(n^2), still pretty fast apparently
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> pascalsTriangle = {{1}};

        for (int i = 1; i <= rowIndex; i++) {
            pascalsTriangle.push_back(generateNthRow(i + 1, pascalsTriangle.back()));
        }

        return pascalsTriangle[rowIndex];
    }

    vector<int> generateNthRow(int rowIndex, vector<int> previousRow) {
        if (rowIndex == 0) return {1};
        if (rowIndex == 1) return {1,1};

        vector<int> generatedRow = {};

        for (int i = 0; i < rowIndex; i++) {
            if (i == 0 || i == rowIndex - 1) { // Handle first and last item in a different way.
                generatedRow.push_back(1);
                continue;
            }

            generatedRow.push_back(previousRow[i-1] + previousRow[i]);
        }

        return generatedRow;
    }
};

// O(n) solution using a Binominal coefficient formula (https://en.wikipedia.org/wiki/Binomial_coefficient)... Yeah, I did not come up with this on my own, full disclosure.
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> resultRow = {1};
        int currentCoefficient = 1;

        for (long i = 1; i <= rowIndex; i++) {
            currentCoefficient = (currentCoefficient * (rowIndex + 1 - i)) / i;
            resultRow.push_back(currentCoefficient);
        }

        return resultRow;
    }
};
