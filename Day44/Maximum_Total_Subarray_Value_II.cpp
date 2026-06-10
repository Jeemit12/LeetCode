/*
You are given an integer array nums of length n and an integer k.

You must select exactly k distinct subarrays nums[l..r] of nums. Subarrays may overlap, but the exact same subarray (same l and r) cannot be chosen more than once.

The value of a subarray nums[l..r] is defined as: max(nums[l..r]) - min(nums[l..r]).

The total value is the sum of the values of all chosen subarrays.

Return the maximum possible total value you can achieve.
*/
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0 || k == 0) return 0;

        vector<int> log2(n + 1, 0);
        for (int i = 2; i <= n; ++i) {
            log2[i] = log2[i / 2] + 1;
        }

        int max_log = log2[n] + 1;
        
        vector<vector<int>> max_st(max_log, vector<int>(n, 0));
        vector<vector<int>> min_st(max_log, vector<int>(n, 0));

        for (int i = 0; i < n; ++i) {
            max_st[0][i] = nums[i];
            min_st[0][i] = nums[i];
        }

        for (int j = 1; j < max_log; ++j) {
            int length = 1 << (j - 1);
            for (int i = 0; i + (1 << j) <= n; ++i) {
                max_st[j][i] = max(max_st[j - 1][i], max_st[j - 1][i + length]);
                min_st[j][i] = min(min_st[j - 1][i], min_st[j - 1][i + length]);
            }
        }

        auto query = [&](int l, int r) -> int {
            if (l == r) return 0;
            int len = r - l + 1;
            int j = log2[len];
            int max_val = max(max_st[j][l], max_st[j][r - (1 << j) + 1]);
            int min_val = min(min_st[j][l], min_st[j][r - (1 << j) + 1]);
            return max_val - min_val;
        };

        priority_queue<pair<int, pair<int, int>>> pq;
        
        auto encode = [&](long long l, long long r) {
            return l * 100005LL + r;
        };

        unordered_set<long long> visited;

       
        int initial_val = query(0, n - 1);
        pq.push({initial_val, {0, n - 1}});
        visited.insert(encode(0, n - 1));

        long long total_value = 0;

        
        for (int i = 0; i < k; ++i) {
            if (pq.empty()) break;

            auto [val, bounds] = pq.top();
            pq.pop();
            
            int l = bounds.first;
            int r = bounds.second;
            
            total_value += val;

            if (l < r) {
                
                long long left_hash = encode(l + 1, r);
                if (visited.find(left_hash) == visited.end()) {
                    visited.insert(left_hash);
                    pq.push({query(l + 1, r), {l + 1, r}});
                }

                long long right_hash = encode(l, r - 1);
                if (visited.find(right_hash) == visited.end()) {
                    visited.insert(right_hash);
                    pq.push({query(l, r - 1), {l, r - 1}});
                }
            }
        }

        return total_value;
    }
};