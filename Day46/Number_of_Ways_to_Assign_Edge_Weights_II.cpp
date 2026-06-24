/*
There is an undirected tree with n nodes labeled from 1 to n, rooted at node 1. The tree is represented by a 2D integer array edges of length n - 1, where edges[i] = [ui, vi] indicates that there is an edge between nodes ui and vi.

Initially, all edges have a weight of 0. You must assign each edge a weight of either 1 or 2.

The cost of a path between any two nodes u and v is the total weight of all edges in the path connecting them.

You are given a 2D integer array queries. For each queries[i] = [ui, vi], determine the number of ways to assign weights to edges in the path such that the cost of the path between ui and vi is odd.

Return an array answer, where answer[i] is the number of valid assignments for queries[i].

Since the answer may be large, apply modulo 109 + 7 to each answer[i].

Note: For each query, disregard all edges not in the path between node ui and vi.
*/
class Solution {
public:
    static constexpr long long MOD = 1'000'000'007LL;

    vector<int> parent, depth;
    vector<vector<int>> up;
    int LOG;

    int lca(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);

        int diff = depth[u] - depth[v];
        for (int j = 0; j < LOG; j++) {
            if (diff & (1 << j))
                u = up[j][u];
        }

        if (u == v) return u;

        for (int j = LOG - 1; j >= 0; j--) {
            if (up[j][u] != up[j][v]) {
                u = up[j][u];
                v = up[j][v];
            }
        }

        return up[0][u];
    }

    long long modPow(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1) res = (res * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return res;
    }

    vector<int> assignEdgeWeights(vector<vector<int>>& edges,
                                  vector<vector<int>>& queries) {
        int n = edges.size() + 1;

        vector<vector<int>> g(n + 1);
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }

        LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        depth.assign(n + 1, 0);
        up.assign(LOG, vector<int>(n + 1, 0));

        queue<int> q;
        q.push(1);
        up[0][1] = 0;

        vector<int> vis(n + 1, 0);
        vis[1] = 1;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : g[u]) {
                if (!vis[v]) {
                    vis[v] = 1;
                    depth[v] = depth[u] + 1;
                    up[0][v] = u;
                    q.push(v);
                }
            }
        }

        for (int j = 1; j < LOG; j++) {
            for (int i = 1; i <= n; i++) {
                int p = up[j - 1][i];
                up[j][i] = p ? up[j - 1][p] : 0;
            }
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto &qu : queries) {
            int u = qu[0], v = qu[1];

            int w = lca(u, v);
            long long dist = (long long)depth[u] + depth[v] - 2LL * depth[w];

            if (dist == 0)
                ans.push_back(0);
            else
                ans.push_back((int)modPow(2, dist - 1));
        }

        return ans;
    }
};