/*
You are given a string s of length m consisting of digits. You are also given a 2D integer array queries, where queries[i] = [li, ri].

For each queries[i], extract the substring s[li..ri]. Then, perform the following:

Form a new integer x by concatenating all the non-zero digits from the substring in their original order. If there are no non-zero digits, x = 0.
Let sum be the sum of digits in x. The answer is x * sum.
Return an array of integers answer where answer[i] is the answer to the ith query.

Since the answers may be very large, return them modulo 109 + 7.
*/
const int MOD = 1e9 + 7;
const int MAX_N = 100001;
long long pow10[MAX_N];

int init = []() {
    pow10[0] = 1;
    for (int i = 1; i < MAX_N; ++i) {
        pow10[i] = (pow10[i - 1] * 10) % MOD;
    }
    return 0;
}();

class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int> sum(n + 1, 0);
        vector<long long> x(n + 1, 0);
        vector<int> cnt(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            int d = s[i] - '0';
            sum[i + 1] = sum[i] + d;
            x[i + 1] = (d > 0) ? (x[i] * 10 + d) % MOD : x[i];
            cnt[i + 1] = cnt[i] + (d > 0);
        }
        int m = queries.size();
        vector<int> res(m, 0);
        for (int i = 0; i < m; ++i) {
            int l = queries[i][0];
            int r = queries[i][1] + 1;
            int length = cnt[r] - cnt[l];
            long long val_x = (x[r] - x[l] * pow10[length] % MOD + MOD) % MOD;
            long long val_sum = sum[r] - sum[l];
            res[i] = (val_x * val_sum) % MOD;
        }
        return res;
    }
};