/*
You are given an integer array nums of length n and an integer k.

For each index i, define its instability score as max(nums[0..i]) - min(nums[i..n - 1]).

In other words:

max(nums[0..i]) is the largest value among the elements from index 0 to index i.
min(nums[i..n - 1]) is the smallest value among the elements from index i to index n - 1.
An index i is called stable if its instability score is less than or equal to k.

Return the smallest stable index. If no such index exists, return -1.
*/
class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size(),maxi=-1;
        if(n==1) return 0;
        vector<int> m(n);
        m[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            m[i]=min(m[i+1],nums[i]);
        }
        for(int i=0;i<n;i++)
        {
            if(nums[i]>maxi) maxi=nums[i];
            int s=maxi-m[i];
            if(s<=k)
            {
                return i;
            }
        }
        return -1;
    }
};