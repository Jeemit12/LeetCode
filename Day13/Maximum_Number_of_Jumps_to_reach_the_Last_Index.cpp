/*
You are given a 0-indexed array nums of n integers and an integer target.

You are initially positioned at index 0. In one step, you can jump from index i to any index j such that:

0 <= i < j < n
-target <= nums[j] - nums[i] <= target
Return the maximum number of jumps you can make to reach index n - 1.

If there is no way to reach index n - 1, return -1.
*/
class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();

        vector<int> dp(n, -1);

        dp[0] = 0;

        for(int i = 1; i < n; i++) {

            for(int j = 0; j < i; j++) {

                if(dp[j] != -1 &&
                   abs(nums[i] - nums[j]) <= target) {

                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        return dp[n - 1];
    }
};