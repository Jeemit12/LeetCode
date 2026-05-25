/*
You are given a 0-indexed binary string s and two integers minJump and maxJump. In the beginning, you are standing at index 0, which is equal to '0'. You can move from index i to index j if the following conditions are fulfilled:

i + minJump <= j <= min(i + maxJump, s.length - 1), and
s[j] == '0'.
Return true if you can reach index s.length - 1 in s, or false otherwise.
*/
class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();

        queue<int> q;
        q.push(0);

        vector<bool> vis(n, false);
        vis[0] = true;

        int far = 1;

        while (!q.empty()) {
            int i = q.front();
            q.pop();

            if (i == n - 1)
                return true;

            int start = max(i + minJump, far);
            int end = min(i + maxJump, n - 1);

            for (int j = start; j <= end; j++) {
                if (s[j] == '0' && !vis[j]) {
                    vis[j] = true;
                    q.push(j);
                }
            }

            far = max(far, i + maxJump + 1);
        }

        return false;
    }
};