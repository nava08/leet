#include <vector>
#include <unordered_set>

class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        // Arrays of sets to track numbers seen so far
        std::unordered_set<char> rows[9];
        std::unordered_set<char> cols[9];
        std::unordered_set<char> boxes[9];

        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                char val = board[r][c];

                // Skip empty cells
                if (val == '.') {
                    continue;
                }

                // Calculate the 3x3 box index
                int box_idx = (r / 3) * 3 + (c / 3);

                // Check if the digit already exists in the current row, column, or box
                if (rows[r].count(val) || cols[c].count(val) || boxes[box_idx].count(val)) {
                    return false;
                }

                // Insert the digit into the respective sets
                rows[r].insert(val);
                cols[c].insert(val);
                boxes[box_idx].insert(val);
            }
        }

        return true;
    }
};