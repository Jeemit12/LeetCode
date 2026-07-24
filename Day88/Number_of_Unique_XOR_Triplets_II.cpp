/*
You are given an integer array nums.

A XOR triplet is defined as the XOR of three elements nums[i] XOR nums[j] XOR nums[k] where i <= j <= k.

Return the number of unique XOR triplet values from all possible triplets (i, j, k).
*/
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        int mx=*max_element(begin(nums),end(nums));
        int t=1;
        while(t<=mx){
            t*=2;
        }
        vector<bool> a(t,false);
        vector<bool> b(t,false);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                a[nums[i]^nums[j]]=true;
            }
        }
        for(int i=0;i<t;i++){
            if(a[i]==true){
                for(int &ns : nums){
                    b[ns^i]=true;
                }
            }
        }
        int c=0;
        for(int i=0;i<t;i++){
            if(b[i]==true){
                c++;
            }
        }
        return c;
    }
};