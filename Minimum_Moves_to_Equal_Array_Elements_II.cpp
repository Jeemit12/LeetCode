/*
Given an integer array nums of sizen, return the minimum number of moves required to make all array elements equal.
in one move, you can increment or decrement an element of the array by 1.
Test cases are designed so that the answer will fit in a
32-bit integer.
*/
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        auto mid = nums.begin() + nums.size() / 2;
        ranges::nth_element(nums, mid);
        int med = *mid, moves = 0;
        for (int x : nums) moves += abs(x - med);
        return moves;
    }
};