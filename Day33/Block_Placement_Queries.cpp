/*
There exists an infinite number line, with its origin at 0 and extending towards the positive x-axis.

You are given a 2D array queries, which contains two types of queries:

For a query of type 1, queries[i] = [1, x]. Build an obstacle at distance x from the origin. It is guaranteed that there is no obstacle at distance x when the query is asked.
For a query of type 2, queries[i] = [2, x, sz]. Check if it is possible to place a block of size sz anywhere in the range [0, x] on the line, such that the block entirely lies in the range [0, x]. A block cannot be placed if it intersects with any obstacle, but it may touch it. Note that you do not actually place the block. Queries are separate.
Return a boolean array results, where results[i] is true if you can place the block specified in the ith query of type 2, and false otherwise.
*/
class Fenwick {
public:
    int n;
    vector<int> bit;

    Fenwick(int n) : n(n), bit(n + 1, 0) {}

    void update(int idx, int val) {
        for (++idx; idx <= n; idx += idx & -idx)
            bit[idx] = max(bit[idx], val);
    }

    int query(int idx) {
        int res = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            res = max(res, bit[idx]);
        return res;
    }
};

class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        vector<int> coords = {0};

        for (auto &q : queries) {
            coords.push_back(q[1]);
        }

        sort(coords.begin(), coords.end());
        coords.erase(unique(coords.begin(), coords.end()), coords.end());

        auto id = [&](int x) {
            return lower_bound(coords.begin(), coords.end(), x) - coords.begin();
        };

        set<int> obstacles = {0};

        for (auto &q : queries) {
            if (q[0] == 1)
                obstacles.insert(q[1]);
        }

        Fenwick fw(coords.size());

        for (auto it = next(obstacles.begin()); it != obstacles.end(); ++it) {
            auto prv = prev(it);
            fw.update(id(*it), *it - *prv);
        }

        vector<bool> ans;

        for (int i = (int)queries.size() - 1; i >= 0; --i) {
            auto &q = queries[i];

            if (q[0] == 2) {
                int x = q[1];
                int sz = q[2];

                auto it = obstacles.upper_bound(x);

                int mx = 0;

                if (it != obstacles.begin()) {
                    auto p = prev(it);
                    mx = max(mx, fw.query(id(*p)));
                    mx = max(mx, x - *p);
                } else {
                    mx = x;
                }

                ans.push_back(mx >= sz);
            }
            else {
                int x = q[1];

                auto cur = obstacles.find(x);
                auto l = prev(cur);
                auto r = next(cur);

                if (r != obstacles.end()) {
                    fw.update(id(*r), *r - *l);
                }

                obstacles.erase(cur);
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};