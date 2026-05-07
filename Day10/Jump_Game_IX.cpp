/*
You are given an integer array nums.

From any index i, you can jump to another index j under the following rules:

Jump to index j where j > i is allowed only if nums[j] < nums[i].
Jump to index j where j < i is allowed only if nums[j] > nums[i].
For each index i, find the maximum value in nums that can be reached by following any sequence of valid jumps starting at i.

Return an array ans where ans[i] is the maximum value reachable starting from index i
*/
class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        vector<int> p(n);
        vector<int> s(n);
        p[0]=nums[0];
        s[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            p[i]=max(p[i-1],nums[i]);
        }
        for(int i=n-2;i>=0;i--){
            s[i]=min(s[i+1],nums[i]);
        }
        ans[n-1]=p[n-1];
        for(int i=n-2;i>=0;i--){
            if(p[i]>s[i+1]){
                ans[i]=ans[i+1];
            }
            else{
                ans[i]=p[i];
            }
        }
        return ans;
    }
};