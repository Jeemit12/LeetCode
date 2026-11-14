/*
You are given an integer array nums and two integers 1 and r. Your task is to find the minimum sum of a subarray whose size is between 1 and r (inclusive) and whose sum is greater than O.
Return the minimum sum of such a subarray. If no such subarray exists, return -1.
A subarray is a contiguous non-empty sequence of elements within an array.
*/
class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                int len = j - i + 1;
                if (len >= l && len <= r && sum > 0) {
                    ans = min(ans, sum);
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};