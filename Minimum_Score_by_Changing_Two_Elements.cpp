/*
You are given an integer array nums.

The low score of nums is the minimum absolute difference between any two integers.
The high score of nums is the maximum absolute difference between any two integers.
The score of nums is the sum of the high and low scores.
Return the minimum score after changing two elements of nums.
*/
class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        array<int, 3> small, large;
        ranges::partial_sort_copy(nums, small);  // the 3 smallest, ascending
        ranges::partial_sort_copy(nums, large, greater{});  // the 3 largest, descending
        return min({large[0] - small[2], large[1] - small[1], large[2] - small[0]});
    }
};