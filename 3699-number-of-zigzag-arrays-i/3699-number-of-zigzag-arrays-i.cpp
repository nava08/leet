#include <vector>
#include <numeric>

class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        const int MOD = 1e9 + 7;
        int m = r - l + 1;
        
        // Re-use pre-allocated vectors to avoid heap allocation overhead inside the loop
        std::vector<long long> dp0(m, 1); // next move down
        std::vector<long long> dp1(m, 1); // next move up
        
        std::vector<long long> next_dp0(m, 0);
        std::vector<long long> next_dp1(m, 0);
        
        std::vector<long long> pref0(m + 1, 0);
        std::vector<long long> pref1(m + 1, 0);
        
        for (int i = 2; i <= n; ++i) {
            // Compute prefix sums inline without creating new structures
            for (int x = 0; x < m; ++x) {
                pref0[x + 1] = (pref0[x] + dp0[x]);
                if (pref0[x + 1] >= MOD) pref0[x + 1] -= MOD;
                
                pref1[x + 1] = (pref1[x] + dp1[x]);
                if (pref1[x + 1] >= MOD) pref1[x + 1] -= MOD;
            }
            
            for (int y = 0; y < m; ++y) {
                // next move down: elements x < y where next move was up
                next_dp0[y] = pref1[y]; 
                
                // next move up: elements x > y where next move was down
                long long val = pref0[m] - pref0[y + 1];
                if (val < 0) val += MOD;
                next_dp1[y] = val;
            }
            
            // Fast pointer/vector swap instead of std::move reconstruction
            dp0.swap(next_dp0);
            dp1.swap(next_dp1);
        }
        
        long long total_arrays = 0;
        for (int x = 0; x < m; ++x) {
            total_arrays = (total_arrays + dp0[x] + dp1[x]) % MOD;
        }
        
        return total_arrays;
    }
};