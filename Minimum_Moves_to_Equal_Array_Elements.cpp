/*
Given an integer array nums of size n, return the minimum number of moves required to make all array elements equal.
In one move, you can increment n - 1 elements of the array by 1.
*/
class Solution {
public:
    int minMoves(vector<int>& nums) {
        return accumulate(nums.begin(), nums.end(), 0ll) - (nums.size() * ranges::min(nums));
    }
};