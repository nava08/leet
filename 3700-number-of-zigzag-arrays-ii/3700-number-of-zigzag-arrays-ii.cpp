#include <vector>

using namespace std;

class Solution {
private:
    long long MOD = 1e9 + 7;

    // Helper function to multiply two matrices
    vector<vector<long long>> multiply(const vector<vector<long long>>& A, const vector<vector<long long>>& B, int size) {
        vector<vector<long long>> C(size, vector<long long>(size, 0));
        for (int i = 0; i < size; ++i) {
            for (int k = 0; k < size; ++k) {
                if (A[i][k] == 0) continue;
                for (int j = 0; j < size; ++j) {
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }
        return C;
    }

    // Helper function for modular matrix exponentiation
    vector<vector<long long>> power(vector<vector<long long>> A, long long p, int size) {
        vector<vector<long long>> res(size, vector<long long>(size, 0));
        for (int i = 0; i < size; ++i) res[i][i] = 1; // Identity matrix

        while (p > 0) {
            if (p & 1) res = multiply(res, A, size);
            A = multiply(A, A, size);
            p >>= 1;
        }
        return res;
    }

public:
    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        int size = 2 * m;

        // Base case: if length is 1, any single value in the range is valid
        if (n == 1) return m; 

        // Construct the transition matrix T of size 2m x 2m
        vector<vector<long long>> T(size, vector<long long>(size, 0));

        for (int x = 0; x < m; ++x) {
            // From (UP, x) -> can go to (DOWN, y) if y > x
            for (int y = x + 1; y < m; ++y) {
                T[x][m + y] = 1;
            }
            // From (DOWN, x) -> can go to (UP, y) if y < x
            for (int y = 0; y < x; ++y) {
                T[m + x][y] = 1;
            }
        }

        // Compute T^(n-1)
        vector<vector<long long>> T_pow = power(T, n - 1, size);

        // Initial state vector: An array of length 1 can transition either UP or DOWN next.
        // So we place a 1 in every starting configuration.
        long long total_valid = 0;
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                total_valid = (total_valid + T_pow[i][j]) % MOD;
            }
        }

        return total_valid;
    }
};