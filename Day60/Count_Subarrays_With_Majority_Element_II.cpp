/*
You are given an integer array nums and an integer target.

Return the number of subarrays of nums in which target is the majority element.

The majority element of a subarray is the element that appears strictly more than half of the times in that subarray.
*/
class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        
        int offset = n + 2; 
        int max_val = 2 * n + 5;
        vector<int> bit(max_val, 0);
        
        auto update = [&](int i, int delta) {
            for (; i < max_val; i += i & -i) {
                bit[i] += delta;
            }
        };
        
        auto query = [&](int i) {
            int sum = 0;
            for (; i > 0; i -= i & -i) {
                sum += bit[i];
            }
            return sum;
        };
        
        long long ans = 0;
        int prefix_sum = 0;
        
        update(prefix_sum + offset, 1);
        
        for (int num : nums) {
    
            if (num == target) {
                prefix_sum += 1;
            } else {
                prefix_sum -= 1;
            }
            
            ans += query(prefix_sum + offset - 1);
            
            update(prefix_sum + offset, 1);
        }
        
        return ans;
    }
};