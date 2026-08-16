class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        vector<int> cnt(3, 0);
        for (int stone : stones) {
            cnt[stone % 3]++;
        }

        if (cnt[0] % 2 == 0) {
            // Even number of 0s: Alice wins if both 1s and 2s are present
            return cnt[1] >= 1 && cnt[2] >= 1;
        } else {
            // Odd number of 0s: Alice wins if the absolute difference between 1s and 2s is greater than 2
            return abs(cnt[1] - cnt[2]) > 2;
        }
    }
};