class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.length();
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }

        for (int i = n - 1; i >= 0; i--) {
            vector<int> current_count = count;
            bool possible = true;
            
            for (int j = 0; j < i; j++) {
                int char_idx = target[j] - 'a';
                if (current_count[char_idx] == 0) {
                    possible = false;
                    break;
                }
                current_count[char_idx]--;
            }

            if (!possible) continue;

            int target_char = target[i] - 'a';
            int next_char = -1;
            for (int c = target_char + 1; c < 26; c++) {
                if (current_count[c] > 0) {
                    next_char = c;
                    break;
                }
            }

            if (next_char != -1) {
                string result = target.substr(0, i);
                result += (char)('a' + next_char);
                current_count[next_char]--;

                for (int c = 0; c < 26; c++) {
                    while (current_count[c] > 0) {
                        result += (char)('a' + c);
                        current_count[c]--;
                    }
                }
                return result;
            }
        }

        return "";
    }
};