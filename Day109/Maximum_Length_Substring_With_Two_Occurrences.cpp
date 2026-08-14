/*
Given a string s, return the maximum length of a substring such that it contains at most two occurrences of each character.
*/
class Solution{
public:
    int maximumLengthSubstring(string s){
        int ans=0,start=-1;
        unordered_map<char,int> m;
        
        for(int i=0;i<s.length();i++){
            m[s[i]]++;
            
            while(m[s[i]]>2){
                start++;
                 m[s[start]]--;
            }
            
            ans=max(ans,i-start);
        }
        
        return ans;
    }
};