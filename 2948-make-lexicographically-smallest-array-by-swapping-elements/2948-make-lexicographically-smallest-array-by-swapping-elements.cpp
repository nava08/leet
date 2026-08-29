class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        
        // Pair each element with its original index: {value, original_index}
        vector<pair<int, int>> sortedNums(n);
        for (int i = 0; i < n; ++i) {
            sortedNums[i] = {nums[i], i};
        }
        
        // Sort elements by value
        sort(sortedNums.begin(), sortedNums.end());
        
        vector<int> result(n);
        
        // Group elements into connected components
        int i = 0;
        while (i < n) {
            int j = i;
            // Find all contiguous elements that belong to the same component
            while (j + 1 < n && sortedNums[j + 1].first - sortedNums[j].first <= limit) {
                j++;
            }
            
            // Extract original indices for this group
            vector<int> indices;
            for (int k = i; k <= j; ++k) {
                indices.push_back(sortedNums[k].second);
            }
            
            // Sort original indices to place smaller values in earlier positions
            sort(indices.begin(), indices.end());
            
            // Place values into result array at sorted positions
            for (int k = 0; k < indices.size(); ++k) {
                result[indices[k]] = sortedNums[i + k].first;
            }
            
            // Move to next component
            i = j + 1;
        }
        
        return result;
    }
};