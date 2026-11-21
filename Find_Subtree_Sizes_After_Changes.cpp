/*
You are given a tree rooted at node 0 that consists of n nodes numbered from 0 to n - 1. The tree is represented by an array parent of size n, where parent[i] is the parent of node i. Since node 0 is the root, parent[0] == -1.

You are also given a string s of length n, where s[i] is the character assigned to node i.

We make the following changes on the tree one time simultaneously for all nodes x from 1 to n - 1:

Find the closest node y to node x such that y is an ancestor of x, and s[x] == s[y].
If node y does not exist, do nothing.
Otherwise, remove the edge between x and its current parent and make node y the new parent of x by adding an edge between them.
Return an array answer of size n where answer[i] is the size of the subtree rooted at node i in the final tree.
*/

class Solution {
public:
    vector<int> ans;

    void dfs(int u, vector<vector<int>>& adj, string& s,
             vector<int>& p, vector<int>& last) {
        int c = s[u] - 'a', old = last[c];

        if (u && old != -1) p[u] = old;
        last[c] = u;

        for (int v : adj[u])
            dfs(v, adj, s, p, last);

        last[c] = old;
    }

    int calc(int u, vector<vector<int>>& tree) {
        ans[u] = 1;
        for (int v : tree[u])
            ans[u] += calc(v, tree);
        return ans[u];
    }

    vector<int> findSubtreeSizes(vector<int>& p, string s) {
        int n = p.size();
        vector<vector<int>> adj(n), tree(n);

        for (int i = 1; i < n; i++)
            adj[p[i]].push_back(i);

        vector<int> last(26, -1);
        dfs(0, adj, s, p, last);

        for (int i = 1; i < n; i++)
            tree[p[i]].push_back(i);

        ans.resize(n);
        calc(0, tree);
        return ans;
    }
};