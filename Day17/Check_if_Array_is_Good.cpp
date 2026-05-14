/*
You are given an integer array nums. We consider an array good if it is a permutation of an array base[n].

base[n] = [1, 2, ..., n - 1, n, n] (in other words, it is an array of length n + 1 which contains 1 to n - 1 exactly once, plus two occurrences of n). For example, base[1] = [1, 1] and base[3] = [1, 2, 3, 3].

Return true if the given array is good, otherwise return false.
*/
class Solution {
public:
    bool isGood(vector<int>& nums) {
       int  n=nums.size()-1;
       sort(nums.begin(),nums.end());
       for(int i=0;i<n;i++){
        if(nums[i]!=i+1) return false;
       }
       return nums[n]==n;
    }
};
// class Solution {
// public:
//     bool isGood(vector<int>& nums) {
//        int  n=nums.size();
//        int mx=0;
//        for(int i=0;i<n;i++){
//             mx=max(nums[i],mx);
//        }
//        if(mx+1==n) return true;
//        else return false;    
//     }
// };
// class Solution {
// public:
//     bool isGood(vector<int>& nums) {
//        int  n=nums.size();
//        sort(nums.begin(),nums.end());
//        if(nums[n-1]!=nums[n-2]) return false;
//        int mx=0;
//        cout<<n<<endl;
//        vector<int> v;
//        for(int i=1;i<=n-1;i++){
//         v.push_back(i);
//        }   
//        v.push_back(nums[n-1]);
//        for(int i=0;i<n;i++){
//         if(v[i]==nums[i]) continue;
//         else return false;
//        }    
//        return true;
//     }
// };
