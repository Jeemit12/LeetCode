/*
You are given an integer array nums of length n and an integer k.

For each index i, define its instability score as max(nums[0..i]) - min(nums[i..n - 1]).

In other words:

max(nums[0..i]) is the largest value among the elements from index 0 to index i.
min(nums[i..n - 1]) is the smallest value among the elements from index i to index n - 1.
An index i is called stable if its instability score is less than or equal to k.

Return the smallest stable index. If no such index exists, return -1.
*/
class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        for (int i = 0; i < n ; i++) {
            int mx = nums[i];

            for (int j = 0; j < i; j++) {
                mx = max(mx, nums[j]);
            }

            int mi = nums[i];

            for (int j = i + 1; j < n; j++) {
                mi = min(mi, nums[j]);
            }

            if (mx - mi <= k) {
                return i;
            }
        }

        return -1;
    }
};