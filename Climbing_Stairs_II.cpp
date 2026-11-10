/*
You are climbing a staircase with n + 1 steps, numbered from 0 to n.

You are also given a 1-indexed integer array costs of length n, where costs[i] is the cost of step i.

From step i, you can jump only to step i + 1 i + 2 or i + 3 The cost of jumping from step i to step j is defined as: costs[j] + (j - i)2

You start from step 0 with cost = 0.

Return the minimum total cost to reach step n.
*/
class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        costs.insert(costs.begin(), 0);
        int a = costs[n], b = INT_MAX / 2, c = INT_MAX / 2;  // dp[i + 1], dp[i + 2], dp[i + 3] for i = n - 1
        for (int i = n - 1; i >= 0; --i) {
            int cur = costs[i] + min({a + 1, b + 4, c + 9});  // dp[i]
            c = b, b = a, a = cur;
        }
        return a;
    }
};