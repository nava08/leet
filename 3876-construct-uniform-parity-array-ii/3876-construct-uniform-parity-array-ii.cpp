class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int min_odd = INT_MAX;
        int min_val = INT_MAX;

        for (int x : nums1) {
            min_val = min(min_val, x);
            if (x % 2 != 0) {
                min_odd = min(min_odd, x);
            }
        }

        // Check if we can make all elements even
        bool can_all_even = true;
        for (int x : nums1) {
            if (x % 2 != 0) {
                // If it's odd, we must be able to subtract an odd number smaller than x
                if (min_odd == INT_MAX || x <= min_odd) {
                    can_all_even = false;
                    break;
                }
            }
        }

        // Check if we can make all elements odd
        bool can_all_odd = true;
        for (int x : nums1) {
            if (x % 2 == 0) {
                // If it's even, we must subtract an odd number to make it odd
                if (min_odd == INT_MAX || x <= min_odd) {
                    can_all_odd = false;
                    break;
                }
            }
        }

        return can_all_even || can_all_odd;
    }
};