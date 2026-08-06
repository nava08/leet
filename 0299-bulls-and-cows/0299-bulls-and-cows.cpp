#include <string>
#include <vector>

class Solution {
public:
    std::string getHint(std::string secret, std::string guess) {
        int bulls = 0;
        int cows = 0;
        std::vector<int> count(10, 0); // Stores frequencies for digits 0-9

        for (size_t i = 0; i < secret.size(); ++i) {
            int s = secret[i] - '0';
            int g = guess[i] - '0';

            if (s == g) {
                bulls++;
            } else {
                // If s was previously seen in guess, it's a cow
                if (count[s] < 0) cows++;
                // If g was previously seen in secret, it's a cow
                if (count[g] > 0) cows++;

                count[s]++; // Track available character from secret
                count[g]--; // Track requested character from guess
            }
        }

        return std::to_string(bulls) + "A" + std::to_string(cows) + "B";
    }
};