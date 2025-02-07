// https://leetcode.com/problems/find-the-number-of-distinct-colors-among-the-balls
// Runtime complexity: O(n) where n is the size of queries input array
// Space complexity: O(n) where n is the size of the limit input
class Solution {
    fun queryResults(limit: Int, queries: Array<IntArray>): IntArray {
        val result : IntArray = IntArray(queries.size) { -1 }
    
        val ballColorMap = hashMapOf<Int, Int>() // ball, color
        val colorFrequencyMap = hashMapOf<Int, Int>() // color, frequency

        queries.forEachIndexed { index, query ->
            val ball = query[0]
            val color = query[1]

            if (ballColorMap.containsKey(ball)) { // The ball already has a color assigned to it.
                val previousColor: Int = ballColorMap[ball]!!
                ballColorMap[ball] = color

                // check the color frequency map and reduce the amount for the key by 1. if it is one, remove it.
                if (colorFrequencyMap[previousColor] == 1) {
                    colorFrequencyMap.remove(previousColor)
                } else {
                    colorFrequencyMap[previousColor] = colorFrequencyMap[previousColor]!! - 1
                }

                colorFrequencyMap[color] = colorFrequencyMap.getOrDefault(color, 0) + 1

            } else { // The ball has no color assigned to it yet.
                ballColorMap[ball] = color
                colorFrequencyMap[color] = colorFrequencyMap.getOrDefault(color, 0) + 1
            }

            // Add the current SIZE of the frequency map to the results
            result[index] = (colorFrequencyMap.size)
        }

        return result
    }
}
