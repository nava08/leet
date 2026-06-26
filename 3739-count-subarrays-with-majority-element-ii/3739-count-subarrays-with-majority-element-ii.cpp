#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Fenwick Tree (Binary Indexed Tree) Implementation
    void update(vector<int>& bit, int idx, int val, int n) {
        for (; idx <= n; idx += idx & -idx) {
            bit[idx] += val;
        }
    }

    int query(vector<int>& bit, int idx) {
        int sum = 0;
        for (; idx > 0; idx -= idx & -idx) {
            sum += bit[idx];
        }
        return sum;
    }

    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        
        // 1. Generate Prefix Sums
        vector<int> pref(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            int val = (nums[i] == target) ? 1 : -1;
            pref[i + 1] = pref[i] + val;
        }

        // 2. Coordinate Compression for Fenwick Tree indices
        vector<int> ranks = pref;
        sort(ranks.begin(), ranks.end());
        ranks.erase(unique(ranks.begin(), ranks.end()), ranks.end());
        
        auto getRank = [&](int val) {
            return lower_bound(ranks.begin(), ranks.end(), val) - ranks.begin() + 1;
        };

        // 3. Count pairs using the Fenwick Tree
        long long totalSubarrays = 0;
        int m = ranks.size();
        vector<int> bit(m + 1, 0);

        for (int i = 0; i <= n; ++i) {
            int currentRank = getRank(pref[i]);
            
            // Query how many previous prefix sums have a strictly smaller value
            totalSubarrays += query(bit, currentRank - 1);
            
            // Add the current prefix sum rank to the Fenwick Tree
            update(bit, currentRank, 1, m);
        }

        return totalSubarrays;
    }
};