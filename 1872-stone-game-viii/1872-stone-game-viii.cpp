class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        
        // Step 1: Compute prefix sums in-place
        vector<long long> pref(n);
        pref[0] = stones[0];
        for (int i = 1; i < n; ++i) {
            pref[i] = pref[i - 1] + stones[i];
        }
        
        // Step 2: Base case at the last element (must take all stones)
        long long maxDiff = pref[n - 1];
        
        // Step 3: Work backwards from n - 2 down to 1 (since Alice must take x > 1 stones)
        for (int i = n - 2; i >= 1; --i) {
            maxDiff = max(maxDiff, pref[i] - maxDiff);
        }
        
        return maxDiff;
    }
};