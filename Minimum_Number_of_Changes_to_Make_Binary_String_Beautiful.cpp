/*
You are given a O-indexed binary strings having an even length.
A string is beautiful if it's possible to partition it into one or more substrings such that:
• Each substring has an even length.
• Each substring contains only 1's or only o's.
You can change any character in s to ø or 1.
Return the minimum number of changes required to make the strings beautiful.
*/
class Solution {
public:
    int minChanges(string s) {
        int minChangesRequired = 0;

        // Check pairs of characters (i, i+1) with step size 2
        for (int i = 0; i < s.length(); i += 2) {
            // If characters in current pair don't match,
            // we need one change to make them equal
            if (s[i] != s[i + 1]) {
                minChangesRequired++;
            }
        }

        return minChangesRequired;
    }
};