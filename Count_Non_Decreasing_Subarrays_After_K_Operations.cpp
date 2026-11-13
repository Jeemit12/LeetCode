/*
You are given an array nums of n integers and an integer k.

For each subarray of nums, you can apply up to k operations on it. In each operation, you increment any element of the subarray by 1.

Note that each subarray is considered independently, meaning changes made to one subarray do not persist to another.

Return the number of subarrays that you can make non-decreasing after performing at most k operations.

An array is said to be non-decreasing if each element is greater than or equal to its previous element, if it exists.
*/
class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), head = n, tail = n, r = n - 1;
        vector<int> starts(n);  // where each plateau starts, left to right: starts[head..tail)
        long long ans = 0, water = 0;
        for (int l = n - 1; l >= 0; --l) {
            int x = nums[l];
            while (head < tail && nums[starts[head]] <= x) {  // x floods the plateau that starts at starts[head]
                int s = starts[head++];
                int end = head < tail ? starts[head] : r + 1;
                water += 1LL * (x - nums[s]) * (end - s);
            }
            starts[--head] = l;
            while (water > k) {  // the right end leaves with its water
                water -= nums[starts[tail - 1]] - nums[r];
                if (starts[tail - 1] == r)
                    --tail;
                --r;
            }
            ans += r - l + 1;
        }
        return ans;
    }
};