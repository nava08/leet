class Solution {
public:
    bool checkDivisibility(int n) {
        int temp = n;
        int digit_sum = 0;
        int digit_product = 1;

        while (temp > 0) {
            int digit = temp % 10;
            digit_sum += digit;
            digit_product *= digit;
            temp /= 10;
        }

        int total_sum = digit_sum + digit_product;

        return n % total_sum == 0;
    }
};