class Solution {
public:
    void backtrack(vector<int>& nums, vector<bool>& visited, vector<int>& current, vector<vector<int>>& result) {
        // Base case: if the current permutation is complete
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            // Skip if the element is already used in the current path
            if (visited[i]) continue;

            // Skip duplicates: if the current element is the same as the previous one,
            // and the previous one hasn't been visited yet in this branch.
            if (i > 0 && nums[i] == nums[i-1] && !visited[i-1]) continue;

            // Make the choice
            visited[i] = true;
            current.push_back(nums[i]);

            // Recurse
            backtrack(nums, visited, current, result);

            // Undo the choice (Backtrack)
            current.pop_back();
            visited[i] = false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        vector<bool> visited(nums.size(), false);

        // Crucial step: sort the array to bring duplicates together
        sort(nums.begin(), nums.end());

        backtrack(nums, visited, current, result);
        return result;
    }
};