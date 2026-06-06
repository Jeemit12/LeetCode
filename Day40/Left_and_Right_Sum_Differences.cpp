/*
You are given a 0-indexed integer array nums of size n.

Define two arrays leftSum and rightSum where:

leftSum[i] is the sum of elements to the left of the index i in the array nums. If there is no such element, leftSum[i] = 0.
rightSum[i] is the sum of elements to the right of the index i in the array nums. If there is no such element, rightSum[i] = 0.
Return an integer array answer of size n where answer[i] = |leftSum[i] - rightSum[i]|.
*/
class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> result;
        int n=nums.size();
        int ts=0;
        for(int x:nums){
            ts+=x;
        }
        int ls=0;
        for(int i=0;i<n;i++){
            int rs=ts-ls-nums[i];
            result.push_back(abs(ls-rs));
            ls+=nums[i];
        }
        return result;
    }
};
// class Solution {
// public:
//     vector<int> leftRightDifference(vector<int>& nums) {
//         vector<int> result;
//         int n=nums.size();
//         int l=0;
//         int h=n-1;
//         for(int i=0;i<n;i++){
//             int ls=0;
//             int rs=0;
//             int j=i;
//             while(j>=l){
//                 ls+=nums[j];
//                 j--;
//             }
//             j=i;
//             while(j<=h){
//                 rs+=nums[j];
//                 j++;
//             }
//             result.push_back(abs(ls-rs));
//         }
//         return result;
//     }
// };