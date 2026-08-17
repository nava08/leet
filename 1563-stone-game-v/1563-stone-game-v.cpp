#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
    int dp[501][501];
    int pref[501];

    int getSum(int i, int j) {
        return pref[j + 1] - pref[i];
    }

    int solve(int i, int j, const vector<int>& stoneValue) {
        if (i == j) return 0; // Only 1 stone left, no score can be earned
        if (dp[i][j] != -1) return dp[i][j];

        int maxScore = 0;
        for (int k = i; k < j; ++k) {
            int leftSum = getSum(i, k);
            int rightSum = getSum(k + 1, j);

            if (leftSum < rightSum) {
                maxScore = max(maxScore, leftSum + solve(i, k, stoneValue));
            } else if (leftSum > rightSum) {
                maxScore = max(maxScore, rightSum + solve(k + 1, j, stoneValue));
            } else { // leftSum == rightSum
                int pickLeft = leftSum + solve(i, k, stoneValue);
                int pickRight = rightSum + solve(k + 1, j, stoneValue);
                maxScore = max(maxScore, max(pickLeft, pickRight));
            }
        }

        return dp[i][j] = maxScore;
    }

public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        fill(&dp[0][0], &dp[0][0] + sizeof(dp) / sizeof(int), -1);

        pref[0] = 0;
        for (int i = 0; i < n; ++i) {
            pref[i + 1] = pref[i] + stoneValue[i];
        }

        return solve(0, n - 1, stoneValue);
    }
};