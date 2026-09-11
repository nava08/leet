#include <vector>
#include <unordered_set>

class Solution {
public:
    int totalNumbers(std::vector<int>& digits) {
        int n = digits.size();
        std::unordered_set<int> unique_numbers;

        for (int i = 0; i < n; ++i) {
            // Units place must be even
            if (digits[i] % 2 != 0) continue;

            for (int j = 0; j < n; ++j) {
                if (i == j) continue; // Cannot reuse the same position

                for (int k = 0; k < n; ++k) {
                    if (k == i || k == j) continue; // Cannot reuse positions

                    // Hundreds place cannot have leading zeros
                    if (digits[k] == 0) continue;

                    int num = digits[k] * 100 + digits[j] * 10 + digits[i];
                    unique_numbers.insert(num);
                }
            }
        }

        return unique_numbers.size();
    }
};