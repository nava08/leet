class Solution {
private:
    int count = 0;
    
    void backtrack(int row, int n, unordered_set<int>& cols, 
                   unordered_set<int>& diag1, unordered_set<int>& diag2) {
        // Base case: If we successfully placed queens in all rows, we found a solution
        if (row == n) {
            count++;
            return;
        }
        
        for (int col = 0; col < n; col++) {
            int d1 = row - col;
            int d2 = row + col;
            
            // If the column or either diagonal is already occupied, skip
            if (cols.count(col) || diag1.count(d1) || diag2.count(d2)) {
                continue;
            }
            
            // Place the queen (Choose)
            cols.insert(col);
            diag1.insert(d1);
            diag2.insert(d2);
            
            // Move to the next row (Explore)
            backtrack(row + 1, n, cols, diag1, diag2);
            
            // Remove the queen (Unchoose / Backtrack)
            cols.erase(col);
            diag1.erase(d1);
            diag2.erase(d2);
        }
    }

public:
    int totalNQueens(int n) {
        unordered_set<int> cols;
        unordered_set<int> diag1; // stores row - col
        unordered_set<int> diag2; // stores row + col
        
        backtrack(0, n, cols, diag1, diag2);
        return count;
    }
};