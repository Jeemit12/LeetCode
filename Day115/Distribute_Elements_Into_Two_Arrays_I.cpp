/*
You are given a 1-indexed array of distinct integers nums of length n.

You need to distribute all the elements of nums between two arrays arr1 and arr2 using n operations. In the first operation, append nums[1] to arr1. In the second operation, append nums[2] to arr2. Afterwards, in the ith operation:

If the last element of arr1 is greater than the last element of arr2, append nums[i] to arr1. Otherwise, append nums[i] to arr2.
The array result is formed by concatenating the arrays arr1 and arr2. For example, if arr1 == [1,2,3] and arr2 == [4,5,6], then result = [1,2,3,4,5,6].

Return the array result.
*/
class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> ans;
        int m1=nums[0],m2=nums[1];
        vector<int> a;
        ans.push_back(m1);
        a.push_back(m2);
        for(int i=2;i<nums.size();i++){
            if(m1>m2){
                ans.push_back(nums[i]);
                m1=nums[i];
            }
            else{
                a.push_back(nums[i]);
                m2=nums[i];
            }
        }
        ans.insert(ans.end(),a.begin(),a.end());
        return ans;
    }
};