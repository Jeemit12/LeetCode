/*
A parentheses string is a non-empty string consisting only of '(' and ')'. It is valid if any of the following conditions is true:

It is ().
It can be written as AB (A concatenated with B), where A and B are valid parentheses strings.
It can be written as (A), where A is a valid parentheses string.
You are given an m x n matrix of parentheses grid. A valid parentheses string path in the grid is a path satisfying all of the following conditions:

The path starts from the upper left cell (0, 0).
The path ends at the bottom-right cell (m - 1, n - 1).
The path only ever moves down or right.
The resulting parentheses string formed by the path is valid.
Return true if there exists a valid parentheses string path in the grid. Otherwise, return false.
*/
class Solution {
public:
    bool hasValidPath(auto& A) {
        int m = A.size(), n = A[0].size();

        if (~(m + n) & 1 || (A[0][0] & 1) || ~A.back().back() & 1)
            return 0;

        vector<bitset<102>> dp(n + 1);
        dp[1].set(0);

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                dp[j + 1] = ((dp[j + 1] | dp[j]) << 1) >> ((A[i][j] & 1) << 1);

        return dp[n].test(0);
    }
};