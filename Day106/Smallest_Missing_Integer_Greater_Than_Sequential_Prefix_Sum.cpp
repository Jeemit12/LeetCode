/*
You are given a 0-indexed array of integers nums.

A prefix nums[0..i] is sequential if, for all 1 <= j <= i, nums[j] = nums[j - 1] + 1. In particular, the prefix consisting only of nums[0] is sequential.

Return the smallest integer x missing from nums such that x is greater than or equal to the sum of the longest sequential prefix.
*/
class Solution {
public:
    int missingInteger(vector<int>& A) {
        int n = A.size();
        unordered_set<int> seen(A.begin(), A.end());
        int sum = A[0];

        for (int i = 1; i < n; i++) {
            if (A[i] == A[i - 1] + 1) sum += A[i];
            else break;
        }

        while (seen.count(sum))
            sum++;

        return sum;
    }
};