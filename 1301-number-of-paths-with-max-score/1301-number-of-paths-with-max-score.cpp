#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        int MOD = 1e9 + 7;
        
        // dp[i][j] will store the max score to reach (i, j) from (0, 0)
        vector<vector<int>> dp(n, vector<int>(n, -1));
        // count[i][j] will store the number of paths achieving that max score
        vector<vector<int>> count(n, vector<int>(n, 0));
        
        // Base case at 'E'
        dp[0][0] = 0;
        count[0][0] = 1;
        
        // Directions to check: Up, Left, Diagonal Up-Left relative to current position
        // Since we iterate forward, we look at where we can come from: (i-1, j), (i, j-1), (i-1, j-1)
        int dirs[3][2] = {{-1, 0}, {0, -1}, {-1, -1}};
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                // Skip the start cell or obstacles
                if ((i == 0 && j == 0) || board[i][j] == 'X') continue;
                
                int max_prev_score = -1;
                int paths = 0;
                
                // Check all 3 incoming paths
                for (int d = 0; d < 3; ++d) {
                    int ni = i + dirs[d][0];
                    int nj = j + dirs[d][1];
                    
                    if (ni >= 0 && nj >= 0 && dp[ni][nj] != -1) {
                        if (dp[ni][nj] > max_prev_score) {
                            max_prev_score = dp[ni][nj];
                            paths = count[ni][nj];
                        } else if (dp[ni][nj] == max_prev_score) {
                            paths = (paths + count[ni][nj]) % MOD;
                        }
                    }
                }
                
                // If at least one valid incoming path exists
                if (max_prev_score != -1) {
                    int current_val = (board[i][j] == 'S') ? 0 : (board[i][j] - '0');
                    dp[i][j] = max_prev_score + current_val;
                    count[i][j] = paths;
                }
            }
        }
        
        // The answer will be at 'S' which is at (n-1, n-1)
        if (dp[n-1][n-1] == -1) {
            return {0, 0};
        }
        
        return {dp[n-1][n-1], count[n-1][n-1]};
    }
};