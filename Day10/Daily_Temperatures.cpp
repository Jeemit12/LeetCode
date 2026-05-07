/*
Given an array of integers temperatures represents the daily temperatures, return an
array answer such that answer[i] is the number of days you have to wait after the ith 
day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.
*/
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int> ans(n);
        stack<int> s;
        for(int i=0;i<n;i++){
            
            while(!s.empty() && temperatures[s.top()]<temperatures[i]){
                int in=s.top();
                ans[in]=i-in;
                s.pop();
            }
            s.push(i);
        }
        return ans;
    }
};