/*
You are given an integer array nums of length n.

You start at index 0, and your goal is to reach index n - 1.

From any index i, you may perform one of the following operations:

Adjacent Step: Jump to index i + 1 or i - 1, if the index is within bounds.
Prime Teleportation: If nums[i] is a prime number p, you may instantly jump to any index j != i such that nums[j] % p == 0.
Return the minimum number of jumps required to reach index n - 1.
*/
class Solution {
public:
    
    bool isPrime(int x) {
        if (x < 2) return false;
        
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) return false;
        }
        
        return true;
    }

    vector<int> getPrimeFactors(int x) {
        vector<int> factors;

        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) {
                factors.push_back(i);

                while (x % i == 0) {
                    x /= i;
                }
            }
        }

        if (x > 1) {
            factors.push_back(x);
        }

        return factors;
    }

    int minJumps(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            vector<int> factors = getPrimeFactors(nums[i]);

            for (int p : factors) {
                mp[p].push_back(i);
            }
        }

        vector<int> dist(n, -1);
        queue<int> q;

        q.push(0);
        dist[0] = 0;

        while (!q.empty()) {
            int i = q.front();
            q.pop();

            if (i == n - 1) {
                return dist[i];
            }


            if (i - 1 >= 0 && dist[i - 1] == -1) {
                dist[i - 1] = dist[i] + 1;
                q.push(i - 1);
            }

            if (i + 1 < n && dist[i + 1] == -1) {
                dist[i + 1] = dist[i] + 1;
                q.push(i + 1);
            }

            if (isPrime(nums[i])) {
                int p = nums[i];

                for (int nxt : mp[p]) {
                    if (dist[nxt] == -1) {
                        dist[nxt] = dist[i] + 1;
                        q.push(nxt);
                    }
                }
                mp[p].clear();
            }
        }

        return -1;
    }
};