/*
You are given a square board of characters. You can move on the board starting at the bottom right square marked with the character 'S'.

You need to reach the top left square marked with the character 'E'. The rest of the squares are labeled either with a numeric character 1, 2, ..., 9 or with an obstacle 'X'. In one move you can go up, left or up-left (diagonally) only if there is no obstacle there.

Return a list of two integers: the first integer is the maximum sum of numeric characters you can collect, and the second is the number of such paths that you can take to get that maximum sum, taken modulo 10^9 + 7.

In case there is no path, return [0, 0].
*/
class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        const int MOD = 1e9 + 7;

        vector<vector<int>> maxSum(n, vector<int>(n, -1));
        vector<vector<int>> ways(n, vector<int>(n, 0));

        maxSum[n-1][n-1] = 0; 
        ways[n-1][n-1] = 1;

        for (int i = n-1; i >= 0; i--) {
            for (int j = n-1; j >= 0; j--) {
                if (board[i][j] == 'X') continue;

                if (i == n-1 && j == n-1) continue;

                int best = -1;
                int count = 0;

                if (i + 1 < n && maxSum[i+1][j] != -1) {
                    best = max(best, maxSum[i+1][j]);
                }
                if (j + 1 < n && maxSum[i][j+1] != -1) {
                    best = max(best, maxSum[i][j+1]);
                }
                if (i + 1 < n && j + 1 < n && maxSum[i+1][j+1] != -1) {
                    best = max(best, maxSum[i+1][j+1]);
                }

                if (best == -1) continue;

                if (i + 1 < n && maxSum[i+1][j] == best)
                    count = (count + ways[i+1][j]) % MOD;
                if (j + 1 < n && maxSum[i][j+1] == best)
                    count = (count + ways[i][j+1]) % MOD;
                if (i + 1 < n && j + 1 < n && maxSum[i+1][j+1] == best)
                    count = (count + ways[i+1][j+1]) % MOD;

                int val = (board[i][j] == 'E') ? 0 : board[i][j] - '0';

                maxSum[i][j] = best + val;
                ways[i][j] = count;
            }
        }

        if (ways[0][0] == 0) return {0, 0};
        return {maxSum[0][0], ways[0][0]};
    }
};