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
public:
    struct Node {
        long long cnt;
        long long wav;
    };

    string s;
    Node memo[20][20][10][10][2][2];
    bool vis[20][20][10][10][2][2];

    Node dfs(int pos,
             int len,
             int p2,
             int p1,
             bool started,
             bool tight) {

        if (pos == (int)s.size())
            return {1, 0};

        if (!tight && vis[pos][len][p2][p1][started][0])
            return memo[pos][len][p2][p1][started][0];

        int limit = tight ? s[pos] - '0' : 9;

        long long totalCnt = 0;
        long long totalWav = 0;

        for (int d = 0; d <= limit; d++) {
            bool ntight = tight && (d == limit);

            if (!started && d == 0) {
                Node nxt = dfs(pos + 1, 0, 0, 0, false, ntight);

                totalCnt += nxt.cnt;
                totalWav += nxt.wav;
            } else {
                if (!started) {
                    Node nxt = dfs(pos + 1, 1, 0, d, true, ntight);

                    totalCnt += nxt.cnt;
                    totalWav += nxt.wav;
                } else {
                    int add = 0;

                    if (len >= 2) {
                        if ((p1 > p2 && p1 > d) ||
                            (p1 < p2 && p1 < d))
                            add = 1;
                    }

                    Node nxt =
                        dfs(pos + 1,
                            len + 1,
                            p1,
                            d,
                            true,
                            ntight);

                    totalCnt += nxt.cnt;
                    totalWav += nxt.wav + 1LL * add * nxt.cnt;
                }
            }
        }

        Node ans = {totalCnt, totalWav};

        if (!tight) {
            vis[pos][len][p2][p1][started][0] = true;
            memo[pos][len][p2][p1][started][0] = ans;
        }

        return ans;
    }

    long long solve(long long n) {
        if (n < 0) return 0;

        memset(vis, 0, sizeof(vis));

        s = to_string(n);
        return dfs(0, 0, 0, 0, false, true).wav;
    }

    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }
};