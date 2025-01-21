// https://leetcode.com/problems/search-a-2d-matrix/

// The requirement is to make the time complexity O(lognm) which this fails as it runs in O(nlogm), but I realized that too late. My proper solution is below.
class Solution {
    fun searchMatrix(matrix: Array<IntArray>, target: Int): Boolean {
        for (row in matrix) {
            if (row.last() < target) continue

            var left = 0
            var right = row.size - 1

            while (left <= right) {
                var center = (left + right) / 2

                if (row[center] < target) {
                    left = center + 1
                } else if (row[center] > target) {
                    right = center -1
                } else {
                    return true
                }
            }
        }

        return false
    }
}

// O(lognm) solution which works by flattening the array (conceptually)
class Solution {
    fun searchMatrix(matrix: Array<IntArray>, target: Int): Boolean {
        val rows = matrix.size
        val columns = matrix[0].size
        var left = 0
        var right = rows * columns - 1

        while (left <= right) {
            val center = (left + right) / 2
            val row = center / columns
            val column = center % columns
            val value = matrix[row][column]

            when {
                value < target -> left = center + 1
                value > target -> right = center - 1
                else -> return true
            }
        }

        return false
    }
}
