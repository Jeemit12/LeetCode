/*
You are given an integer array nums consisting of unique integers.

Originally, nums contained every integer within a certain range. However, some integers might have gone missing from the array.

The smallest and largest integers of the original range are still present in nums.

Return a sorted list of all the missing integers in this range. If no integers are missing, return an empty list.
*/
class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int> ans;
        int j=0;
        for(int i=nums[0];i<=nums[n-1];i++){
            if(i!=nums[j]) ans.push_back(i);
            if(i==nums[j]) j++;
        }
        return ans;
    }
};