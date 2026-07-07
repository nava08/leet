class Solution {
private:
    // Memoization table: -1 = unvisited, 0 = false, 1 = true
    vector<vector<int>> memo;

    bool dfs(int i, int j, const string& s, const string& p) {
        // Base case: If we reached the end of the pattern, 
        // we must also be at the end of the string for a valid match.
        if (j == p.length()) {
            return i == s.length();
        }

        // Return cached result if already calculated
        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        // Check if the current characters match (or if pattern has '.')
        bool firstMatch = (i < s.length() && (s[i] == p[j] || p[j] == '.'));

        bool ans = false;

        // If the next character in the pattern is '*', we have two choices:
        if (j + 1 < p.length() && p[j + 1] == '*') {
            ans = dfs(i, j + 2, s, p) ||            // Choice 1: Skip the '*' (match 0 times)
                  (firstMatch && dfs(i + 1, j, s, p)); // Choice 2: Consume 1 char of 's' if it matches
        } else {
            // No '*', so just move forward if the current characters match
            ans = firstMatch && dfs(i + 1, j + 1, s, p);
        }

        return memo[i][j] = ans;
    }

public:
    bool isMatch(string s, string p) {
        // Size is (s.length() + 1) x (p.length() + 1) to handle out-of-bounds base cases
        memo.assign(s.length() + 1, vector<int>(p.length() + 1, -1));
        return dfs(0, 0, s, p);
    }
};