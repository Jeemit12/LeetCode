/*
Given a string s and an integer k, partition s into k substrings such that the letter changes needed to make each substring a semi-palindrome are minimized.
Return the minimum number of letter changes required.
A semi-palindrome is a special type of string that can be divided into palindromes based on a repeating pattern. To check if a string is a semi-palindrome:
1. Choose a positive divisor d of the string's length. d can range from 1 up to, but not including, the string's length. For a string of length 1, it does not have a valid divisor as per this definition, since the only divisor is its length, which is not allowed.
2. For a given divisor d, divide the string into groups where each group contains characters from the string that follow a repeating pattern of length d.
Specifically, the first group consists of characters at positions 1, 1 + d, 1 + 2d, and so on; the second group includes characters at positions 2, 2 + d, 2 + 2d, etc.
3. The string is considered a semi-palindrome if each of these groups torms a palindrome.
Consider the string "abcabc":
• The length of "abcabc" is 6. Valid divisors are 1, 2, and 3.
• For d = 1: The entire string "abcabc" forms one group. Not a palindrome.
• For d = 2:
• Group 1 (positions 1, 3, 5): "acb"
• Group 2 (positions 2, 4, 6): "bac"
• Neither group forms a palindrome.
• For d = 3:
• Group 1 (positions 1, 4): "aa"
• Group 2 (positions 2, 5): "bb"
• Group 3 (positions 3, 6): "cc"
• All groups form palindromes. Therefore,
"abcabc" is a semi-palindrome.
*/
class Solution {
    int segmentCost(const string& s, int l, int m,
                    const vector<vector<int>>& factors) {
        int best = m;
        for (int d : factors[m]) {
            int groups = m / d;  // Each group contains groups characters
            int changes = 0;
            for (int offset = 0; offset < d; offset++) {
                for (int t = 0; t < groups / 2;
                     t++) {  // Pair characters from opposite ends of the group
                    if (s[l + offset + t * d] !=
                        s[l + offset + (groups - 1 - t) * d]) {
                        changes++;
                    }
                }
            }
            best = min(best, changes);
        }
        return best;
    }

public:
    int minimumChanges(string s, int k) {
        int n = s.length();
        vector<vector<int>> factors(n + 1);
        // Precompute the proper divisors of each number
        for (int d = 1; d <= n / 2; d++) {
            for (int m = d * 2; m <= n; m += d) {
                factors[m].push_back(d);
            }
        }
        vector cost(n, vector<int>(n, 0));
        for (int l = 0; l + 1 < n; l++) {
            for (int r = l + 1; r < n;
                 r++) {  // Each substring must have length at least 2
                cost[l][r] = segmentCost(s, l, r - l + 1, factors);
            }
        }
        vector<int> prev(n);
        for (int start = 0; start < n; start++) {  // The case seg = 1
            prev[start] = cost[start][n - 1];
        }
        for (int seg = 2; seg <= k;
             seg++) {  // Increase the number of segments from 2 to k
            vector<int> cur(n, n);
            int limit = n - 1 - 2 * (seg - 1);
            for (int start = 0; start + 2 * seg <= n;
                 start++) {  // Leave at least 2*seg characters
                for (int e = start + 1; e <= limit; e++) {
                    cur[start] = min(cur[start], cost[start][e] + prev[e + 1]);
                }
            }
            prev.swap(cur);
        }
        return prev[0];
    }
};