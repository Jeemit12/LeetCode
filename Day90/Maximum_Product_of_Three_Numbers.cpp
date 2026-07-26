/*
Given an integer array nums, find three numbers whose product is maximum and return the maximum product.
*/
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n=nums.size();
        int m1=INT_MAX,m2=INT_MAX,mx1=INT_MIN,mx2=INT_MIN,mx3=INT_MIN;
        for(int i=0;i<n;i++){
            if(nums[i]<m1){
                m2=m1;
                m1=nums[i];
            }
            else if(nums[i]<m2){
                m2=nums[i];
            }
            if(nums[i]>mx1){
                mx3=mx2;
                mx2=mx1;
                mx1=nums[i];
            }
            else if(nums[i]>mx2){
                mx3=mx2;
                mx2=nums[i];
            }
            else if(nums[i]>mx3){
                mx3=nums[i];
            }
        }
        return max(m1*m2*mx1,mx1*mx2*mx3);
    }
};