/*
You are given a 0-indexed integer array nums and a positive integer k.

You can do the following operation on the array any number of times:

Choose any two distinct indices i and j and simultaneously update the values of nums[i] to (nums[i] AND nums[j]) and nums[j] to (nums[i] OR nums[j]). Here, OR denotes the bitwise OR operation, and AND denotes the bitwise AND operation.
You have to choose k elements from the final array and calculate the sum of their squares.

Return the maximum sum of squares you can achieve.

Since the answer can be very large, return it modulo 109 + 7.
*/
class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        vector<long long> base;
        long long x = 1;

        while (x <= 1000000000) {
            base.push_back(x);
            x <<= 1;
        }

        int nb = base.size();
        vector<int> count(nb, 0);

        for (int x : nums) {
            for (int i = 0; i < nb; i++) {
                if (x & base[i])
                    count[i]++;
            }
        }

        vector<long long> values(k, 0);

        for (int i = 0; i < nb; i++) {
            for (int j = 0; j < min(k, count[i]); j++) {
                values[j] += base[i];
            }
        }

        long long res = 0;
        const long long mod = 1000000007;

        for (long long y : values) {
            res = (res + y * y) % mod;
        }

        return res;
    }
};