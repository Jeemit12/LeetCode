/*
You are given three integers n, l, and r.

A ZigZag array of length n is defined as follows:

Each element lies in the range [l, r].
No two adjacent elements are equal.
No three consecutive elements form a strictly increasing or strictly decreasing sequence.
Return the total number of valid ZigZag arrays.

Since the answer may be large, return it modulo 109 + 7.

A sequence is said to be strictly increasing if each element is strictly greater than its previous one (if exists).

A sequence is said to be strictly decreasing if each element is strictly smaller than its previous one (if exists).
*/
class Solution {
public:
    static const int MOD = 1e9 + 7;

    using Matrix = vector<vector<long long>>;

    Matrix multiply(Matrix &A, Matrix &B) {
        int n = A.size();
        Matrix C(n, vector<long long>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if (A[i][k] == 0) continue;

                long long val = A[i][k];

                for (int j = 0; j < n; j++) {
                    C[i][j] = (C[i][j] + val * B[k][j]) % MOD;
                }
            }
        }
        return C;
    }

    Matrix power(Matrix base, long long exp) {
        int n = base.size();
        Matrix result(n, vector<long long>(n, 0));

        for (int i = 0; i < n; i++)
            result[i][i] = 1;

        while (exp) {
            if (exp & 1)
                result = multiply(result, base);

            base = multiply(base, base);
            exp >>= 1;
        }
        return result;
    }

    vector<long long> multiplyVec(Matrix &A, vector<long long> &v) {
        int n = A.size();
        vector<long long> res(n, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res[i] = (res[i] + A[i][j] * v[j]) % MOD;
            }
        }
        return res;
    }

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        int sz = 2 * m;

        vector<long long> state(sz);

        for (int i = 0; i < m; i++) {
            state[i] = i;
            state[m + i] = m - 1 - i;
        }

        if (n == 2) {
            long long ans = 0;
            for (auto x : state) ans = (ans + x) % MOD;
            return ans;
        }

        Matrix T(sz, vector<long long>(sz, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < i; j++) {
                T[i][m + j] = 1;
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m; j++) {
                T[m + i][j] = 1;
            }
        }

        Matrix P = power(T, n - 2);
        vector<long long> finalState = multiplyVec(P, state);

        long long ans = 0;
        for (auto x : finalState)
            ans = (ans + x) % MOD;

        return ans;
    }
};