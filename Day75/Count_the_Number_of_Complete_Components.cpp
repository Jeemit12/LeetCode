/*
You are given an integer n. There is an undirected graph with n vertices, numbered from 0 to n - 1. You are given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting vertices ai and bi.

Return the number of complete connected components of the graph.

A connected component is a subgraph of a graph in which there exists a path between any two vertices, and no vertex of the subgraph shares an edge with a vertex outside of the subgraph.

A connected component is said to be complete if there exists an edge between every pair of its vertices.
*/
class Solution {
public:
    vector<vector<int>> graph;
    vector<int> vis;
    int nodes;
    long long degreeSum;

    void dfs(int u) {
        vis[u] = 1;
        nodes++;
        degreeSum += graph[u].size();

        for (int v : graph[u]) {
            if (!vis[v])
                dfs(v);
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        graph.assign(n, {});
        vis.assign(n, 0);

        for (auto &e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                nodes = 0;
                degreeSum = 0;

                dfs(i);

                if (degreeSum == 1LL * nodes * (nodes - 1))
                    ans++;
            }
        }

        return ans;
    }
};