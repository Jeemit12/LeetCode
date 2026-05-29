/*
You are given an integer array nums.

You replace each element in nums with the sum of its digits.

Return the minimum element in nums after all replacements.
*/
class Solution {
public:
    int minElement(vector<int>& nums) {
        int mn = INT_MAX;

        for (int x : nums) {
            int sum = 0;
            do {
                sum += x % 10;
                x /= 10;
            } while (x);

            mn = min(mn, sum);
        }

        return mn;
    }
};