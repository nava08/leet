#include <vector>
#include <algorithm>
#include <cmath>

class Solution {
public:
    int findRadius(std::vector<int>& houses, std::vector<int>& heaters) {
        std::sort(heaters.begin(), heaters.end());
        int minRadius = 0;
        
        for (int house : houses) {
            // Find the first heater >= house
            auto it = std::lower_bound(heaters.begin(), heaters.end(), house);
            
            int distToRight = (it != heaters.end()) ? (*it - house) : INT_MAX;
            int distToLeft = (it != heaters.begin()) ? (house - *(it - 1)) : INT_MAX;
            
            int closestHeater = std::min(distToLeft, distToRight);
            minRadius = std::max(minRadius, closestHeater);
        }
        
        return minRadius;
    }
};