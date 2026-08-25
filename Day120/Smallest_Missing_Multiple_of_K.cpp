/*
Given an integer array nums and an integer k, return the smallest positive multiple of k that is missing from nums.

A multiple of k is any positive integer divisible by k.
*/
class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(auto i:nums){
            m[i]=1;
        }
        int n=1;
        while(1){
            if(m[k*n]==1){
                n+=1;
                continue;
            }
            break;
        }
        return n*k;
    }
};