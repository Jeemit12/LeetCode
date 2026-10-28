/*
You are given a 2D integer array grid of size m * n.
You start at the top-left cell (ø, ø) and want to reach the bottom-right cell (m - 1, n - 1).
At each step, you may move either right or down.
The cost of a path is defined as the bitwise XOR of all the values in the cells along that path, including the start and end cells.
Return the minimum possible XOR value among all valid paths from (0, 0) to (m - 1, n - 1).
*/
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        const int m = grid.size();
        const int n = grid[0].size();

        vector<array<bool, 1024>> dp(n);
        array<bool, 1024> next{};

        dp[0][grid[0][0]] = true;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }

                const int value = grid[i][j];
                next.fill(false);

                for (int k = 0; k < 1024; k++) {
                    if (dp[j][k] || (j > 0 && dp[j - 1][k])) {
                        next[k ^ value] = true;
                    }
                }

                dp[j] = next;
            }
        }

        for (int k = 0; k < 1024; k++) {
            if (dp[n - 1][k]) {
                return k;
            }
        }

        return -1;
    }
};