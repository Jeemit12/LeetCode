/*
Given two strings s and t, return the number of distinct subsequences of s which equals t.

The test cases are generated so that the answer fits on a 32-bit signed integer.
*/
unsigned dp[1001];
class Solution {
public:
    static int numDistinct(string& s, string& t) {
        const int m=s.size(), n=t.size();
        memset(dp, 0, sizeof(unsigned)*(n+1));
        dp[0]=1;
        for(int i=1; i<=m; i++){
            for(int j=min(i, n); j>=1; j--){
                if (s[i-1]==t[j-1]) dp[j]+=dp[j-1];
            }
        }
        return dp[n];
    }
};