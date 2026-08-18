/*
You are given an integer array nums and an integer k.

An integer x is almost missing from nums if x appears in exactly one subarray of size k within nums.

Return the largest almost missing integer from nums. If no such integer exists, return -1.

A subarray is a contiguous sequence of elements within an array.
*/
class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==k) return *max_element(nums.begin(),nums.end());
        int a=count(nums.begin(),nums.end(),nums[0]);
        int b=count(nums.begin(),nums.end(),nums[nums.size()-1]);
        int count[51] = {0};
        for(int i:nums){
            count[i]++;
        }
        if(k==1) {
            for(int i=50;i>=0;i--){
                if(count[i]==1) return i;
                
            }
            return -1;
            
        }
        if(a==1 && b==1) {
            return max(nums[0],nums[nums.size()-1]);
        }
        if(a==1) return nums[0];
        if(b==1) return nums[nums.size()-1];
        return -1;
        }  
};