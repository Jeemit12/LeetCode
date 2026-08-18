/*
There are several stones arranged in a row, and each stone has an associated value which is an integer given in the array stoneValue.

In each round of the game, Alice divides the row into two non-empty rows (i.e. left row and right row), then Bob calculates the value of each row which is the sum of the values of all the stones in this row. Bob throws away the row which has the maximum value, and Alice's score increases by the value of the remaining row. If the value of the two rows are equal, Bob lets Alice decide which row will be thrown away. The next round starts with the remaining row.

The game ends when there is only one stone remaining. Alice's score is initially zero.

Return the maximum score that Alice can obtain.
*/
class Solution {
private:
    vector<vector<int>> f;

public:
    int dfs(const vector<int>& stoneValue, int left, int right) {
        if (left == right) {
            return 0;
        }
        if (f[left][right]) {
            return f[left][right];
        }

        int sum = accumulate(stoneValue.begin() + left,
                             stoneValue.begin() + right + 1, 0);
        int suml = 0;
        for (int i = left; i < right; ++i) {
            suml += stoneValue[i];
            int sumr = sum - suml;
            if (suml < sumr) {
                f[left][right] =
                    max(f[left][right], dfs(stoneValue, left, i) + suml);
            } else if (suml > sumr) {
                f[left][right] =
                    max(f[left][right], dfs(stoneValue, i + 1, right) + sumr);
            } else {
                f[left][right] =
                    max(f[left][right], max(dfs(stoneValue, left, i),
                                            dfs(stoneValue, i + 1, right)) +
                                            suml);
            }
        }
        return f[left][right];
    }

    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        f.assign(n, vector<int>(n));
        return dfs(stoneValue, 0, n - 1);
    }
};