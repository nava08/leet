class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.length();
        vector<int> count(26, 0);
        for (char c : s) count[c - 'a']++;

        int odd_count = 0;
        char mid_char = 0;
        for (int i = 0; i < 26; ++i) {
            if (count[i] % 2 != 0) {
                odd_count++;
                mid_char = 'a' + i;
            }
        }

        if ((n % 2 == 0 && odd_count > 0) || (n % 2 != 0 && odd_count != 1)) {
            return "";
        }

        int half_len = n / 2;
        vector<int> half_count(26, 0);
        for (int i = 0; i < 26; ++i) {
            half_count[i] = count[i] / 2;
        }

        auto make_palindrome = [&](const string& left_half) {
            string res = left_half;
            if (n % 2 != 0) res += mid_char;
            string rev = left_half;
            reverse(rev.begin(), rev.end());
            res += rev;
            return res;
        };

        string best_ans = "";

        for (int prefix_len = half_len; prefix_len >= 0; --prefix_len) {
            vector<int> rem = half_count;
            bool possible = true;
            string prefix = "";

            for (int i = 0; i < prefix_len; ++i) {
                int c = target[i] - 'a';
                if (rem[c] > 0) {
                    rem[c]--;
                    prefix += target[i];
                } else {
                    possible = false;
                    break;
                }
            }

            if (!possible) continue;

            if (prefix_len == half_len) {
                string cand = make_palindrome(prefix);
                if (cand > target) {
                    if (best_ans == "" || cand < best_ans) best_ans = cand;
                }
                continue;
            }

            int target_char = target[prefix_len] - 'a';
            for (int next_char = target_char + 1; next_char < 26; ++next_char) {
                if (rem[next_char] > 0) {
                    string cand_half = prefix;
                    cand_half += (char)('a' + next_char);
                    
                    vector<int> cur_rem = rem;
                    cur_rem[next_char]--;

                    for (int c = 0; c < 26; ++c) {
                        cand_half.append(cur_rem[c], 'a' + c);
                    }

                    string cand = make_palindrome(cand_half);
                    if (cand > target) {
                        if (best_ans == "" || cand < best_ans) {
                            best_ans = cand;
                        }
                    }
                }
            }
        }

        return best_ans;
    }
};