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

        long long minLandFinish = LLONG_MAX;
        for (int i = 0; i < landStartTime.size(); i++) {
            minLandFinish = min(
                minLandFinish,
                (long long)landStartTime[i] + landDuration[i]
            );
        }

        long long minWaterFinish = LLONG_MAX;
        for (int i = 0; i < waterStartTime.size(); i++) {
            minWaterFinish = min(
                minWaterFinish,
                (long long)waterStartTime[i] + waterDuration[i]
            );
        }

        long long ans = LLONG_MAX;
        for (int j = 0; j < waterStartTime.size(); j++) {
            ans = min(
                ans,
                max(minLandFinish, (long long)waterStartTime[j]) +
                waterDuration[j]
            );
        }
        for (int i = 0; i < landStartTime.size(); i++) {
            ans = min(
                ans,
                max(minWaterFinish, (long long)landStartTime[i]) +
                landDuration[i]
            );
        }

        return ans;
    }
};