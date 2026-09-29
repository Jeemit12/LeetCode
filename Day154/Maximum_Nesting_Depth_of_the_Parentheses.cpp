/*
Given a valid parentheses string s, return the nesting depth of s. The nesting depth is the maximum number of nested parentheses
*/
class Solution {
public:
    int maxDepth(string s) {
        int ans=0;
        int op=0;
        for(char c:s){
            if(c=='(') op++;
            else if(c==')') op--;
            ans=max(ans,op);
        }
        return ans;
    
    }
};