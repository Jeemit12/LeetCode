/*
You are given a string word. A letter is called special if it appears both in lowercase and uppercase in word.

Return the number of special letters in word.
*/
class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char> lower, upper;
        
        for (char ch : word) {
            if (islower(ch))
                lower.insert(ch);
            else
                upper.insert(tolower(ch));
        }

        int count = 0;

        for (char ch : lower) {
            if (upper.count(ch))
                count++;
        }

        return count;
    }
};