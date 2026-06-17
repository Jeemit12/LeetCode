/*
You are given a string s consisting of lowercase English letters and the special characters: '*', '#', and '%'.

You are also given an integer k.

Build a new string result by processing s according to the following rules from left to right:

If the letter is a lowercase English letter append it to result.
A '*' removes the last character from result, if it exists.
A '#' duplicates the current result and appends it to itself.
A '%' reverses the current result.
Return the kth character of the final string result. If k is out of the bounds of result, return '.'.
*/
class Solution {
public:
    char processStr(string s, long long k) {
        const long long INF = 4e18;

        int n = s.size();
        vector<long long> len(n + 1, 0);

        for (int i = 0; i < n; i++) {
            char ch = s[i];
            long long cur = len[i];

            if ('a' <= ch && ch <= 'z')
                len[i + 1] = min(INF, cur + 1);
            else if (ch == '*')
                len[i + 1] = (cur > 0 ? cur - 1 : 0);
            else if (ch == '#')
                len[i + 1] = min(INF, cur * 2);
            else if (ch == '%')
                len[i + 1] = cur;
        }

        if (k < 0 || k >= len[n]) return '.';

        long long idx = k;

        for (int i = n - 1; i >= 0; i--) {
            char ch = s[i];

            if ('a' <= ch && ch <= 'z') {
                if (idx == len[i + 1] - 1)
                    return ch;
            }
            else if (ch == '#') {
                if (len[i] > 0)
                    idx %= len[i];
            }
            else if (ch == '%') {
                idx = len[i] - 1 - idx;
            }
        }

        return '.';
    }
};