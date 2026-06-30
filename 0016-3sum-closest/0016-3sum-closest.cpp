class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // Sort the array to use the two-pointer approach
        sort(nums.begin(), nums.end());
        
        // Initialize closest_sum with the sum of the first three elements
        int closest_sum = nums[0] + nums[1] + nums[2];
        int n = nums.size();
        
        for (int i = 0; i < n - 2; ++i) {
            int left = i + 1;
            int right = n - 1;
            
            while (left < right) {
                int current_sum = nums[i] + nums[left] + nums[right];
                
                // If we find an exact match, return it immediately
                if (current_sum == target) {
                    return current_sum;
                }
                
                // If the current sum is closer to target, update closest_sum
                if (abs(current_sum - target) < abs(closest_sum - target)) {
                    closest_sum = current_sum;
                }
                
                // Move pointers based on comparison with target
                if (current_sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        
        return closest_sum;
    }
};