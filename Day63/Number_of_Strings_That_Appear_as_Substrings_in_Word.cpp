/*
Given an array of strings patterns and a string word, return the number of strings in patterns that exist as a substring in word.

A substring is a contiguous sequence of characters within a string.
*/
class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count = 0;

        for (string pattern : patterns) {
            if (word.find(pattern) != string::npos) {
                count++;
            }
        }

        return count;
    }
};