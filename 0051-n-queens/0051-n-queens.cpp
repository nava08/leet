class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        
        // Trackers for columns and diagonals
        vector<bool> cols(n, false);
        vector<bool> posDiag(2 * n, false); // r + c
        vector<bool> negDiag(2 * n, false); // r - c + n (offset to keep index positive)
        
        backtrack(0, n, board, ans, cols, posDiag, negDiag);
        return ans;
    }

private:
    void backtrack(int r, int n, vector<string>& board, vector<vector<string>>& ans,
                   vector<bool>& cols, vector<bool>& posDiag, vector<bool>& negDiag) {
        if (r == n) {
            ans.push_back(board);
            return;
        }
        
        for (int c = 0; c < n; ++c) {
            // Check if column or diagonals are under attack
            if (cols[c] || posDiag[r + c] || negDiag[r - c + n]) {
                continue;
            }
            
            // Place the queen
            board[r][c] = 'Q';
            cols[c] = posDiag[r + c] = negDiag[r - c + n] = true;
            
            // Move to the next row
            backtrack(r + 1, n, board, ans, cols, posDiag, negDiag);
            
            // Backtrack (remove the queen)
            board[r][c] = '.';
            cols[c] = posDiag[r + c] = negDiag[r - c + n] = false;
        }
    }
};