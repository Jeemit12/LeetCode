/*
You are given two categories of theme park attractions: land rides and water rides.

Land rides
landStartTime[i] – the earliest time the ith land ride can be boarded.
landDuration[i] – how long the ith land ride lasts.
Water rides
waterStartTime[j] – the earliest time the jth water ride can be boarded.
waterDuration[j] – how long the jth water ride lasts.
A tourist must experience exactly one ride from each category, in either order.

A ride may be started at its opening time or any later moment.
If a ride is started at time t, it finishes at time t + duration.
Immediately after finishing one ride the tourist may board the other (if it is already open) or wait until it opens.
Return the earliest possible time at which the tourist can finish both rides.
*/
class Solution {
public:
    long long earliestFinishTime(vector<int>& landStartTime,
                                 vector<int>& landDuration,
                                 vector<int>& waterStartTime,
                                 vector<int>& waterDuration) {

        auto solveOrder = [&](const vector<int>& startA,
                              const vector<int>& durA,
                              const vector<int>& startB,
                              const vector<int>& durB) -> long long {

            int m = startB.size();

            vector<pair<long long,long long>> ridesB;
            for (int i = 0; i < m; i++) {
                ridesB.push_back({startB[i], durB[i]});
            }

            sort(ridesB.begin(), ridesB.end());

            vector<long long> starts(m);
            vector<long long> prefMinDur(m);
            vector<long long> suffMinOpenPlusDur(m);

            for (int i = 0; i < m; i++) {
                starts[i] = ridesB[i].first;
            }

            for (int i = 0; i < m; i++) {
                if (i == 0)
                    prefMinDur[i] = ridesB[i].second;
                else
                    prefMinDur[i] =
                        min(prefMinDur[i - 1], ridesB[i].second);
            }

            for (int i = m - 1; i >= 0; i--) {
                long long val = ridesB[i].first + ridesB[i].second;

                if (i == m - 1)
                    suffMinOpenPlusDur[i] = val;
                else
                    suffMinOpenPlusDur[i] =
                        min(suffMinOpenPlusDur[i + 1], val);
            }

            long long best = LLONG_MAX;

            int n = startA.size();
            for (int i = 0; i < n; i++) {
                long long endA = (long long)startA[i] + durA[i];

                int pos = lower_bound(
                    starts.begin(), starts.end(), endA
                ) - starts.begin();

                long long cur = LLONG_MAX;

                
                if (pos < m)
                    cur = min(cur, suffMinOpenPlusDur[pos]);

                
                if (pos > 0)
                    cur = min(cur, endA + prefMinDur[pos - 1]);

                best = min(best, cur);
            }

            return best;
        };

        long long ans1 = solveOrder(
            landStartTime, landDuration,
            waterStartTime, waterDuration
        ); 

        long long ans2 = solveOrder(
            waterStartTime, waterDuration,
            landStartTime, landDuration
        ); 

        return min(ans1, ans2);
    }
};