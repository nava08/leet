#pragma GCC optimize("O3")
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        
        int maxLen = 0;
        
        // 1. Handle the special case of 1s
        if (freq.count(1)) {
            int count1 = freq[1];
            // We need an odd number of elements for the symmetric pattern
            if (count1 % 2 == 0) {
                maxLen = max(maxLen, count1 - 1);
            } else {
                maxLen = max(maxLen, count1);
            }
        }
        
        // 2. Process all other base elements > 1
        for (auto& [val, count] : freq) {
            if (val == 1) continue;
            
            long long current = val;
            int currentLen = 0;
            
            // Keep extending the chain as long as we have at least 2 copies of the current element
            while (freq.count(current) && freq[current] >= 2) {
                currentLen += 2;
                current = current * current; // Move to the next square
            }
            
            // Check if the next square exists at least once to serve as the peak
            if (freq.count(current) && freq[current] >= 1) {
                currentLen += 1;
            } else {
                // If there's no peak element available, the last element we took 2 copies of 
                // must turn into the peak, so we subtract 1 from the sequence.
                currentLen -= 1;
            }
            
            maxLen = max(maxLen, currentLen);
        }
        
        return maxLen;
    }
};