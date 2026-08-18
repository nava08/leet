#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> subarrayCount;

        // Iterate through every subarray of length k
        for (int i = 0; i <= n - k; ++i) {
            unordered_set<int> uniqueInSubarray;
            for (int j = i; j < i + k; ++j) {
                uniqueInSubarray.insert(nums[j]);
            }
            for (int val : uniqueInSubarray) {
                subarrayCount[val]++;
            }
        }

        // Find the maximum value with frequency == 1
        int ans = -1;
        for (auto& [val, count] : subarrayCount) {
            if (count == 1) {
                ans = max(ans, val);
            }
        }

        return ans;
    }
};