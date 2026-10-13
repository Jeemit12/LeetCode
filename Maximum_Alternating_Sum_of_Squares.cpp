/*
You are given an integer array nums. You may rearrange the elements in any order.
The alternating score of an array arr is defined as:
• score = arr [0] - arr [1] + arr [2] - arr [3]2 + ...
Return an integer denoting the maximum possible alternating score of nums after rearranging its elements.
*/
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<long long> sq;
        for (int x : nums) sq.push_back(1LL * x * x);
        int h = sq.size() / 2;
        nth_element(sq.begin(), sq.begin() + h, sq.end());  
        long long total = accumulate(sq.begin(), sq.end(), 0LL);
        long long small = accumulate(sq.begin(), sq.begin() + h, 0LL);
        return total - 2 * small; 
    }
};