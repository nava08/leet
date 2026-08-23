class Solution {
public:
    bool sumGame(string num) {
        int n = num.length();
        int sumLeft = 0, sumRight = 0;
        int qLeft = 0, qRight = 0;

        for (int i = 0; i < n / 2; ++i) {
            if (num[i] == '?') qLeft++;
            else sumLeft += num[i] - '0';
        }

        for (int i = n / 2; i < n; ++i) {
            if (num[i] == '?') qRight++;
            else sumRight += num[i] - '0';
        }

        // Bob wins if and only if:
        // 2 * (sumLeft - sumRight) == 9 * (qRight - qLeft)
        return 2 * (sumLeft - sumRight) != 9 * (qRight - qLeft);
    }
};