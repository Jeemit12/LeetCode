/*
You are given an integer array nums of even length n and an integer limit. In one move, you can replace any integer from nums with another integer between 1 and limit, inclusive.

The array nums is complementary if for all indices i (0-indexed), nums[i] + nums[n - 1 - i] equals the same number. For example, the array [1,2,3,4] is complementary because for all indices i, nums[i] + nums[n - 1 - i] = 5.

Return the minimum number of moves required to make nums complementary.
*/
class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {

        int n = nums.size();

        vector<int> diff(2*limit + 2, 0);

        for(int i = 0; i < n/2; i++) {

            int a = nums[i];
            int b = nums[n-1-i];
            int low = min(a,b);
            int high = max(a,b);
            diff[2] += 2;
            diff[2*limit + 1] -= 2;

            diff[low+1] -= 1;
            diff[high+limit+1] += 1;

           
            diff[a+b] -= 1;
            diff[a+b+1] += 1;
        }

        int ans = INT_MAX;
        int curr = 0;

        for(int s = 2; s <= 2*limit; s++) {
            curr += diff[s];
            ans = min(ans, curr);
        }

        return ans;
    }
};
// class Solution {
// public:
//     int minMoves(vector<int>& nums, int limit) {
//         int a=0;
//         int n=nums.size();
//         int ans=INT_MAX;
//         for(int target=2;target<=2*limit;target++){
//             int moves=0;
//             for(int i=0;i<n/2;i++){
//                 int a=nums[i];
//                 int b=nums[n-1-i];
//                 if(a+b==target){
//                     continue;
//                 }
//                 else if(target-a>=1 && target-a<=limit){
//                     moves++;
//                 }
//                 else if(target-b>=1 && target-b<=limit){
//                     moves++;
//                 }
//                 else{
//                     moves+=2;
//                 }    
//             }
//             ans=min(ans,moves);
//         }
//         return ans;
//     }
// };