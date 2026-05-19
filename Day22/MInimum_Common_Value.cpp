/*
Given two integer arrays nums1 and nums2, sorted in non-decreasing order, return the minimum integer common to both arrays. If there is no common integer amongst nums1 and nums2, return -1.

Note that an integer is said to be common to nums1 and nums2 if both arrays have at least one occurrence of that integer.
*/
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int i=0;
        int j=0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]==nums2[j]){
                return nums2[j];
            }
            if(nums1[i]<nums2[j]){
                i++;
            }
            else{
                j++;
            }
        }
        return -1;  
    }
};
// class Solution {
// public:
//     int getCommon(vector<int>& nums1, vector<int>& nums2) {
//         int n=nums1.size();
//         int m=nums2.size();
//         if(n<m){
//             int i=0;
//             while(i<n){
//                 int target=nums1[i];
//                 int l=0;
//                 int h=m-1;
//                 while(l<=h){
//                     int mid=l+(h-l)/2;
//                     if(nums2[mid]==target) return target;
//                     if(target>nums2[mid]){
//                         l=mid+1;
//                     }
//                     else{
//                         h=mid-1;
//                     }
//                 }
//                 i++;
//             }
//         }
//         else{
//             int i=0;
//             while(i<m){
//                 int target=nums2[i];
//                 int l=0;
//                 int h=n-1;
//                 while(l<=h){
//                     int mid=l+(h-l)/2;
//                     if(nums1[mid]==target) return target;
//                     if(target>nums1[mid]){
//                         l=mid+1;
//                     }
//                     else{
//                         h=mid-1;
//                     }
//                 }
//                 i++;
//             }
//         }
//         return -1;  
//     }
// };