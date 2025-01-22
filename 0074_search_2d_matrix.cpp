// https://leetcode.com/problems/search-a-2d-matrix/description/
// O(lognm) solution that works by flattening the 2d matrix, treating it as a sorted array and doing binary search on that array.
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int columns = matrix[0].size();

        int startIndex = 0;
        int endIndex = rows * columns - 1;

        while (startIndex <= endIndex) {
            int centerIndex = (startIndex + endIndex) / 2;

            int rowOfCenter = centerIndex / columns;
            int columnOfCenter = centerIndex % columns;

            if (matrix[rowOfCenter][columnOfCenter] < target) {
                startIndex = centerIndex + 1;
            } else if (matrix[rowOfCenter][columnOfCenter] > target) {
                endIndex = centerIndex - 1;
            } else {
                return true;
            }
        }

        return false;
    }
};
