/*
You are given an integer array nums of length n, where nums is a permutation of the integers from 0 to n - 1.

You may perform only the following operations:

Reverse the entire array.
Rotate Left by One: Move the first element to the end of the array, and rest elements to left by one position.
Return an integer denoting the minimum number of operations required to sort the array in increasing order. If it is not possible to sort the array using only the given operations, return -1.
*/
class Solution {
public:
    int minOperations(vector<int>& nums) {
        const int n = nums.size();
        if (n == 1) {
            return 0;
        }

        const int start = find(nums.begin(), nums.end(), 0) - nums.begin();
        bool asc = true;
        bool desc = true;

        for (int i = 1; i < n; i++) {
            const int value = nums[(start + i) % n];

            if (value != i) {
                asc = false;
            }
            if (value != n - i) {
                desc = false;
            }

            if (!asc && !desc) {
                return -1;
            }
        }

        if (asc) {
            return min(start, n - start + 2);
        }

        return min(n - start, start + 2);
    }
};