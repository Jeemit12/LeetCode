/*
You have k servers numbered from 0 to k-1 that are being used to handle multiple requests simultaneously. Each server has infinite computational capacity but cannot handle more than one request at a time. The requests are assigned to servers according to a specific algorithm:

The ith (0-indexed) request arrives.
If all servers are busy, the request is dropped (not handled at all).
If the (i % k)th server is available, assign the request to that server.
Otherwise, assign the request to the next available server (wrapping around the list of servers and starting from 0 if necessary). For example, if the ith server is busy, try to assign the request to the (i+1)th server, then the (i+2)th server, and so on.
You are given a strictly increasing array arrival of positive integers, where arrival[i] represents the arrival time of the ith request, and another array load, where load[i] represents the load of the ith request (the time it takes to complete). Your goal is to find the busiest server(s). A server is considered busiest if it handled the most number of requests successfully among all the servers.

Return a list containing the IDs (0-indexed) of the busiest server(s). You may return the IDs in any order.
*/
class Solution {
    struct Job {
        int at;  // the time its server frees up
        int server;
        auto operator<=>(const Job&) const = default;
    };
    template <class T> using MinHeap = priority_queue<T, vector<T>, greater<>>;

public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        vector<int> turns(k);
        iota(turns.begin(), turns.end(), 0);  // at request 0, server x's next turn is x
        MinHeap<int> free(greater<>{}, std::move(turns));  // each free server, keyed by its next turn

        MinHeap<Job> busy;
        vector<int> handled(k);
        for (int i = 0; i < ssize(arrival); ++i) {
            while (!busy.empty() && busy.top().at <= arrival[i]) {  // done by the arrival
                int x = busy.top().server;
                busy.pop();
                free.push(i + (x - i % k + k) % k);  // its first turn from i on
            }
            if (free.empty()) continue;  // none free: the request is dropped
            int x = free.top() % k;
            free.pop();
            busy.push({arrival[i] + load[i], x});
            ++handled[x];
        }

        int most = ranges::max(handled);
        vector<int> ans;
        for (int x = 0; x < k; ++x)
            if (handled[x] == most) ans.push_back(x);
        return ans;
    }
};