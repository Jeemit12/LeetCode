/*
Given two sorted arrays nums1 and nums2 
of size m and n respectively, return the 
median of the two sorted arrays.
The overall run time complexity should be O(log (m+n)).*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> m_arr;
        int n=nums1.size();
        int m=nums2.size();
        int j=0,k=0;
        while(j<n && k<m){
        if(nums1[j]<nums2[k]){
            m_arr.push_back(nums1[j]);
            j++;
        }
        else{
            m_arr.push_back(nums2[k]);
            k++;
        }
        }
        while(j<n){
            m_arr.push_back(nums1[j]);
            j++;
        }
        while(k<m){
            m_arr.push_back(nums2[k]);
            k++;
        }
        int a=n+m;
        double r;
        if(a%2==0){
            int b=a/2;
            r=(m_arr[b]+m_arr[b-1])/2.0;
            return r; 
        }
        else {
            int b=(int)(n+m)/2;
            r=(double)m_arr[b];
            return r;
        }
        
    }
};
// #include<algorithm>
// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         vector<int> m_arr;
//         int n=nums1.size();
//         int m=nums2.size();
//         for(int i=0;i<n;i++){
//             m_arr.push_back(nums1[i]);
//         }
//         for(int i=0;i<m;i++){
//             m_arr.push_back(nums2[i]);
//         }
//         sort(m_arr.begin(),m_arr.end());
//         int a=n+m;
//         double r;
//         if(a%2==0){
//             int b=a/2;
//             r=(m_arr[b]+m_arr[b-1])/2.0;
//             return r; 
//         }
//         else {
//             int b=(int)(n+m)/2;
//             r=(double)m_arr[b];
//             return r;
//         }
        
//     }
// };