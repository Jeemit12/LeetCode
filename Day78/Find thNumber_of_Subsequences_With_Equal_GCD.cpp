/*
You are given an integer array nums.

Your task is to find the number of pairs of non-empty subsequences (seq1, seq2) of nums that satisfy the following conditions:

The subsequences seq1 and seq2 are disjoint, meaning no index of nums is common between them.
The GCD of the elements of seq1 is equal to the GCD of the elements of seq2.
Return the total number of such pairs.

Since the answer may be very large, return it modulo 109 + 7.
*/
class Solution {
public:
    static const int MOD = 1e9 + 7;

    int subsequencePairCount(vector<int>& nums) {
        const int MAX = 200;

        vector<vector<int>> dp(MAX + 1, vector<int>(MAX + 1, 0));
        vector<vector<int>> ndp(MAX + 1, vector<int>(MAX + 1, 0));

        dp[0][0] = 1;

        for (int x : nums) {

            for (int i = 0; i <= MAX; i++)
                fill(ndp[i].begin(), ndp[i].end(), 0);

            for (int g1 = 0; g1 <= MAX; g1++) {
                for (int g2 = 0; g2 <= MAX; g2++) {

                    if (dp[g1][g2] == 0)
                        continue;

                    long long ways = dp[g1][g2];

                    ndp[g1][g2] =
                        (ndp[g1][g2] + ways) % MOD;

                    int ng1 = (g1 == 0) ? x : gcd(g1, x);

                    ndp[ng1][g2] =
                        (ndp[ng1][g2] + ways) % MOD;

                    int ng2 = (g2 == 0) ? x : gcd(g2, x);

                    ndp[g1][ng2] =
                        (ndp[g1][ng2] + ways) % MOD;
                }
            }

            dp.swap(ndp);
        }

        long long ans = 0;

        for (int g = 1; g <= MAX; g++) {
            ans += dp[g][g];
            ans %= MOD;
        }

        return ans;
    }
};