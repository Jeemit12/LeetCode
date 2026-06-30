/*
Given a string s consisting only of characters a, b and c.

Return the number of substrings containing at least one occurrence of all these characters a, b and c.
*/
class Solution {
public:
    int numberOfSubstrings(string s) {
        int count[3] = {0}; 
        int left = 0;
        int ans = 0;
        int n = s.size();

        for (int right = 0; right < n; right++) {
            count[s[right] - 'a']++;

            while (count[0] > 0 && count[1] > 0 && count[2] > 0) {
                ans += (n - right);
                count[s[left] - 'a']--;
                left++;
            }
        }

        return ans;
    }
};