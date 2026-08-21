class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();

        // Helper function to count amounts <= target using Inclusion-Exclusion
        auto count = [&](long long target) {
            long long total = 0;
            // Iterate through all 2^n - 1 non-empty subsets using bitmask
            for (int mask = 1; mask < (1 << n); ++mask) {
                long long current_lcm = 1;
                int set_bits = 0;
                bool overflow = false;

                for (int i = 0; i < n; ++i) {
                    if ((mask >> i) & 1) {
                        set_bits++;
                        current_lcm = std::lcm(current_lcm, (long long)coins[i]);
                        if (current_lcm > target) {
                            overflow = true;
                            break;
                        }
                    }
                }

                if (overflow) continue;

                if (set_bits % 2 == 1) {
                    total += target / current_lcm;
                } else {
                    total -= target / current_lcm;
                }
            }
            return total;
        };

        // Binary search range for the answer
        long long low = 1;
        long long high = 1LL * *min_element(coins.begin(), coins.end()) * k;
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (count(mid) >= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};