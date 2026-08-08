/*
You are given two strings word1 and word2.

A string x is called almost equal to y if you can change at most one character in x to make it identical to y.

A sequence of indices seq is called valid if:

The indices are sorted in ascending order.
Concatenating the characters at these indices in word1 in the same order results in a string that is almost equal to word2.
Return an array of size word2.length representing the lexicographically smallest valid sequence of indices. If no such sequence of indices exists, return an empty array.

Note that the answer must represent the lexicographically smallest array, not the corresponding string formed by those indices.
*/
class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.length(), m = word2.length();
        vector<int> last(m, -1);
        int j = m - 1;
        for (int i = n - 1; i >= 0; --i) {
            if (j >= 0 && word1[i] == word2[j]) {
                last[j] = i;
                j -= 1;
            }
        }
        vector<int> res;
        int skip = 0;
        j = 0;
        for (int i = 0; i < n; ++i) {
            if (j == m) break;
            if (word1[i] == word2[j] ||
                (skip == 0 && (j == m - 1 || i < last[j + 1]))) {
                skip += (word1[i] != word2[j] ? 1 : 0);
                res.push_back(i);
                j += 1;
            }
        }
        return j == m ? res : vector<int>();
    }
};