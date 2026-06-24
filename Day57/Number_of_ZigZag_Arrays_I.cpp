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

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        if (n == 1) return m;

        vector<int> up(m + 2), down(m + 2);
        vector<int> newUp(m + 2), newDown(m + 2);

        for (int x = 1; x <= m; x++) {
            up[x] = x - 1;
            down[x] = m - x;
        }

        for (int len = 3; len <= n; len++) {

            long long pref = 0;
            for (int x = 1; x <= m; x++) {
                newUp[x] = pref;
                pref += down[x];
                if (pref >= MOD) pref -= MOD;
            }

            long long suff = 0;
            for (int x = m; x >= 1; x--) {
                newDown[x] = suff;
                suff += up[x];
                if (suff >= MOD) suff -= MOD;
            }

            swap(up, newUp);
            swap(down, newDown);
        }

        long long ans = 0;
        for (int x = 1; x <= m; x++) {
            ans += up[x] + down[x];
            ans %= MOD;
        }

        return ans;
    }
};