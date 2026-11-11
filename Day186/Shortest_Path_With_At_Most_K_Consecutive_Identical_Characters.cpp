/*
You are given an integer n representing the number of nodes in a directed weighted graph, numbered from 0 to n - 1. This is represented by a 2D integer array
edges, where edges [I] = [ui, Vi, Wi] represents a
directed edge from node u; to node V; with weight Wi.
You are also given a string labels of length n, where labelslil is the character assigned to node i, and an integer k.
Return the minimum total edge weight of a path from node 0 to node n - 1 such that the concatenation of the labels of the nodes along the path contains at most k consecutive identical characters. If no valid path exists, return -1.
*/
class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> g(n);
        for (auto& e : edges) {
            g[e[0]].emplace_back(e[1], e[2]);
        }

        vector dis(n, vector<long long>(k + 1, INT_MAX));
        // {shortest path length, node index, number of consecutive identical
        // letters at the end}
        priority_queue<tuple<long long, int, int>,
                       vector<tuple<long long, int, int>>, greater<>>
            pq;

        dis[0][1] = 0;
        pq.emplace(0, 0, 1);

        while (!pq.empty()) {
            auto [d, x, cnt] = pq.top();
            pq.pop();

            if (d > dis[x][cnt]) {
                continue;
            }
            if (x == n - 1) {
                return d;
            }

            for (auto [y, w] : g[x]) {
                int new_cnt = labels[x] == labels[y] ? cnt + 1 : 1;
                if (new_cnt > k) {
                    continue;
                }

                long long nd = d + w;
                if (nd < dis[y][new_cnt]) {
                    dis[y][new_cnt] = nd;
                    pq.emplace(nd, y, new_cnt);
                }
            }
        }

        return -1;
    }
};