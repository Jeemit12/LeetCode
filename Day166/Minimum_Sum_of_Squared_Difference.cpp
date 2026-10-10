/*
You are given two positive 0-indexed integer arrays nums1 and nums2, both of length n.

The sum of squared difference of arrays nums1 and nums2 is defined as the sum of (nums1[i] - nums2[i])2 for each 0 <= i < n.

You are also given two positive integers k1 and k2. You can modify any of the elements of nums1 by +1 or -1 at most k1 times. Similarly, you can modify any of the elements of nums2 by +1 or -1 at most k2 times.

Return the minimum sum of squared difference after modifying array nums1 at most k1 times and modifying array nums2 at most k2 times.

Note: You are allowed to modify the array elements to become negative integers.
*/
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size(), M = 0;
        long long k = 1LL * k1 + k2;
        vector<int> diff(n);

        for (int i = 0; i < n; i++)
            M = max(M, diff[i] = abs(nums1[i] - nums2[i]));

        vector<int> bucket(M + 1);
        for (int x : diff) bucket[x]++;

        for (int i = M; i > 0 && k > 0; i--) {
            int take = min((long long)bucket[i], k);
            bucket[i] -= take;
            bucket[i - 1] += take;
            k -= take;
        }

        long long ans = 0;
        for (int i = 1; i <= M; i++)
            ans += 1LL * bucket[i] * i * i;

        return ans;
    }
};