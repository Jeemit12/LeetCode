/*
You are given a binary string s of length n, where:

'1' represents an active section.
'0' represents an inactive section.
You can perform at most one trade to maximize the number of active sections in s. In a trade, you:

Convert a contiguous block of '1's that is surrounded by '0's to all '0's.
Afterward, convert a contiguous block of '0's that is surrounded by '1's to all '1's.
Return the maximum number of active sections in s after making the optimal trade.

Note: Treat s as if it is augmented with a '1' at both ends, forming t = '1' + s + '1'. The augmented '1's do not contribute to the final count.
*/
class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n=s.length();
        int active=count(s.begin(),s.end(),'1');
        vector<int> inactive;
        int i=0;
        while(i<n){
            if(s[i]=='0'){
                int start=i;
                while(i<n && s[i]=='0') i++;
                inactive.push_back(i-start);

            }
            else{
                i++;
            }
        }
        int mx=0;
        for(int i=1;i<inactive.size();i++){
            mx=max(mx,inactive[i]+inactive[i-1]);
        }
        return mx+active;
    }
};