#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int maxProfit = 0;
        
        // Accumulate every positive profit from price increases
        for (size_t i = 1; i < prices.size(); ++i) {
            if (prices[i] > prices[i - 1]) {
                maxProfit += prices[i] - prices[i - 1];
            }
        }
        
        return maxProfit;
    }
};