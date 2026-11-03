/*
You are given an integer array nums.

In one move, you may increase the value of any single element nums [i] by 1.

Return the minimum total number of moves required so that all elements in nums become equal.
*/
class Solution {
public:
    long long minMoves(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());
        long long res = 0;
        for (int x : nums) {
            res += (mx - x);
        }
        return res;
    }
};