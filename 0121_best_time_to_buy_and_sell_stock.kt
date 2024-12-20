// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

// Super quick and rough O(n^2) solution that probably runs out of time with the larger test cases
class Solution {
    fun maxProfit(prices: IntArray): Int {
        var currentMaxProfit = 0

        for (currentDay in prices.indices) {
            for (nextDay in (currentDay + 1) until prices.size) {
                var potentialProfit = prices[nextDay] - prices[currentDay]
                
                if (potentialProfit > 0 && potentialProfit > currentMaxProfit) {
                    currentMaxProfit = potentialProfit
                }
            }
        }

        return currentMaxProfit
    }
}

// O(n) two pointers approach. :) 
class Solution {
    fun maxProfit(prices: IntArray): Int { 
        if (prices.size == 1) return 0
        
        var currentMaxProfit = 0;
        var left = 0; // Buying value Pointer
        var right = 1; // Selling value Pointer

        for (i in prices.indices - 1) { 
            if (prices[right] < prices[left]) {
                left = right
                right++
                continue
            }

            val potentialProfit = prices[right] - prices[left] 
            right++
            if (potentialProfit > currentMaxProfit) currentMaxProfit = potentialProfit 
        }

        return currentMaxProfit;
    }
}
