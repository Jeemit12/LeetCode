/*
You are given an array of positive integers nums.

You need to select a subset of nums which satisfies the following condition:

You can place the selected elements in a 0-indexed array such that it follows the pattern: [x, x2, x4, ..., xk/2, xk, xk/2, ..., x4, x2, x] (Note that k can be be any non-negative power of 2). For example, [2, 4, 16, 4, 2] and [3, 9, 3] follow the pattern while [2, 4, 8, 4, 2] does not.
Return the maximum number of elements in a subset that satisfies these conditions.
*/
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> freq;
        for (int x : nums) freq[x]++;

        int ans = 1;

        if (freq.count(1)) {
            int c = freq[1];
            ans = max(ans, c % 2 ? c : c - 1);
        }

        for (auto &[num, cnt] : freq) {
            if (num == 1) continue;

            long long x = num;
            int len = 0;

            while (freq[x] >= 2 && freq.count(x * x)) {
                len += 2;
                x = x * x;
            }

            if (freq[x] >= 1) len++;

            ans = max(ans, len);
        }

        return ans;
    }
};