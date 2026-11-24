/*
You are given an array of positive integers nums.

An array arr is called product equivalent if prod(arr) == lcm(arr) * gcd(arr), where:

prod(arr) is the product of all elements of arr.
gcd(arr) is the GCD of all elements of arr.
lcm(arr) is the LCM of all elements of arr.
Return the length of the longest product equivalent subarray of nums.
*/
class Solution {
public:
    int maxLength(vector<int>& nums) {
        int res = 2;
        int prodVal = 1;
        int n = nums.size();
        int start = 0, end = 0;

        while (end < n) {
            while (gcd(prodVal, nums[end]) > 1) {
                prodVal /= nums[start];
                start++;
            }
            prodVal *= nums[end];
            res = max(res, end - start + 1);
            end++;
        }
        return res;
    }
};