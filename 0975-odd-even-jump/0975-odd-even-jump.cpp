#include <vector>
#include <map>

class Solution {
public:
    int oddEvenJumps(std::vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return n;

        std::vector<bool> higher(n, false); // can reach end starting with an odd jump
        std::vector<bool> lower(n, false);  // can reach end starting with an even jump

        // Base cases: already at the destination
        higher[n - 1] = true;
        lower[n - 1] = true;

        std::map<int, int> map;
        map[arr[n - 1]] = n - 1;

        int goodCount = 1; // index n-1 is always good

        for (int i = n - 2; i >= 0; --i) {
            // Find next destination for ODD jump (smallest value >= arr[i])
            auto hi = map.lower_bound(arr[i]);
            if (hi != map.end()) {
                higher[i] = lower[hi->second];
            }

            // Find next destination for EVEN jump (largest value <= arr[i])
            auto lo = map.upper_bound(arr[i]);
            if (lo != map.begin()) {
                --lo;
                lower[i] = higher[lo->second];
            }

            // A starting index always begins with an ODD jump (1st jump)
            if (higher[i]) {
                goodCount++;
            }

            map[arr[i]] = i;
        }

        return goodCount;
    }
};