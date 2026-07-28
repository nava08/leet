#include <vector>
#include <algorithm>

class Solution {
public:
    int carFleet(int target, std::vector<int>& position, std::vector<int>& speed) {
        int n = position.size();
        if (n == 0) return 0;

        // Pair up position and speed
        std::vector<std::pair<int, int>> cars(n);
        for (int i = 0; i < n; ++i) {
            cars[i] = {position[i], speed[i]};
        }

        // Sort cars by position in descending order (closest to target first)
        std::sort(cars.rbegin(), cars.rend());

        int fleets = 0;
        double maxTime = 0.0;

        for (int i = 0; i < n; ++i) {
            // Time to reach target = (target - position) / speed
            double time = static_cast<double>(target - cars[i].first) / cars[i].second;

            // If this car takes strictly more time than the leading fleet, it forms a new fleet
            if (time > maxTime) {
                fleets++;
                maxTime = time; // Update maxTime to the speed-limiting car of the new fleet
            }
        }

        return fleets;
    }
};