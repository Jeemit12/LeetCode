/*
You are given two integers num1 and num2 representing an inclusive range [num1, num2].

The waviness of a number is defined as the total count of its peaks and valleys:

A digit is a peak if it is strictly greater than both of its immediate neighbors.
A digit is a valley if it is strictly less than both of its immediate neighbors.
The first and last digits of a number cannot be peaks or valleys.
Any number with fewer than 3 digits has a waviness of 0.
Return the total sum of waviness for all numbers in the range [num1, num2].
*/
class Solution {
    struct Node {
        long long cnt;
        long long wav;
    };

    string s;
    Node memo[20][2][11][11];
    bool vis[20][2][11][11];

    Node dfs(int pos, bool started, int prev1, int prev2, bool tight) {
        if (pos == (int)s.size()) {
            return {1, 0};
        }

        if (!tight && vis[pos][started][prev1 + 1][prev2 + 1]) {
            return memo[pos][started][prev1 + 1][prev2 + 1];
        }

        int limit = tight ? (s[pos] - '0') : 9;

        Node res = {0, 0};

        for (int d = 0; d <= limit; d++) {
            bool ntight = tight && (d == limit);

            if (!started) {
                if (d == 0) {
                    Node child = dfs(pos + 1, false, -1, -1, ntight);
                    res.cnt += child.cnt;
                    res.wav += child.wav;
                } else {
                    Node child = dfs(pos + 1, true, d, -1, ntight);
                    res.cnt += child.cnt;
                    res.wav += child.wav;
                }
            } else {
                int add = 0;

                if (prev2 != -1) {
                    if ((prev1 > prev2 && prev1 > d) ||
                        (prev1 < prev2 && prev1 < d)) {
                        add = 1;
                    }
                }

                Node child = dfs(pos + 1, true, d, prev1, ntight);

                res.cnt += child.cnt;
                res.wav += child.wav + 1LL * add * child.cnt;
            }
        }

        if (!tight) {
            vis[pos][started][prev1 + 1][prev2 + 1] = true;
            memo[pos][started][prev1 + 1][prev2 + 1] = res;
        }

        return res;
    }

    long long solve(long long x) {
        if (x < 0) return 0;

        s = to_string(x);
        memset(vis, 0, sizeof(vis));

        return dfs(0, false, -1, -1, true).wav;
    }

public:
    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }
};