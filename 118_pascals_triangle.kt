// https://leetcode.com/problems/pascals-triangle/description/

// Rough-ish first solution. O(n^2) because for we are doing iterating twice. 
class Solution {
    fun generate(numRows: Int): List<List<Int>> {
        val finalList: MutableList<List<Int>> = mutableListOf()

        // For how many numbers of rows required, call the generateRowFunction, providing the [previousRow] and the elements in the current row
        for (i in 1..numRows) {
            if (i == 1) {
                finalList.add(listOf(1))
            } else if (i == 2) {
                finalList.add(listOf(1,1))
            } else {
                finalList.add(generateRow(previousRow = finalList.last(), elementsInRow = i))
            }
        }

        return finalList
    }

    // Generates a single row of [elementsInRow] elements, given the previous row of [previousRow]
    fun generateRow(previousRow: List<Int>, elementsInRow: Int): List<Int> {
        val newRow: MutableList<Int> = mutableListOf()

        for (i in 0..elementsInRow - 1) {
            // Handle first & last item specially
            if (i == 0 || i == elementsInRow - 1) {
                newRow.add(1)
                continue
            }
                
            newRow.add(previousRow[i-1] + previousRow[i])
        }

        return newRow
    }
}
