#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    // Fenwick Tree (Binary Indexed Tree) implementation
    void update(vector<int>& bit, int idx, int val, int max_idx) {
        for (; idx <= max_idx; idx += idx & -idx) {
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

public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        
        // The prefix sum can range from -n to n. 
        // We shift everything by + (n + 1) to make all indices positive and 1-based.
        int offset = n + 1;
        int max_idx = 2 * n + 2;
        
        // Size the vector to max_idx + 1 so that accessing bit[max_idx] is perfectly safe
        vector<int> bit(max_idx + 1, 0);
        
        long long valid_subarrays_count = 0;
        int current_prefix_sum = 0;
        
        // Initialize the Fenwick Tree with the initial prefix sum P[0] = 0
        update(bit, current_prefix_sum + offset, 1, max_idx);
        
        for (int num : nums) {
            // Transform to +1 if match, else -1
            current_prefix_sum += (num == target) ? 1 : -1;
            
            // Query the number of elements strictly less than current_prefix_sum
            valid_subarrays_count += query(bit, current_prefix_sum + offset - 1);
            
            // Add the current prefix sum to the Fenwick Tree
            update(bit, current_prefix_sum + offset, 1, max_idx);
        }
        
        return valid_subarrays_count;
    }
};