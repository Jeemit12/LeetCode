/*
You are given five integers cost1, cost2, costBoth, need1, and need2.

There are three types of items available:

An item of type 1 costs cost1 and contributes 1 unit to the type 1 requirement only.
An item of type 2 costs cost2 and contributes 1 unit to the type 2 requirement only.
An item of type 3 costs costBoth and contributes 1 unit to both type 1 and type 2 requirements.
You must collect enough items so that the total contribution toward type 1 is at least need1 and the total contribution toward type 2 is at least need2.

Return an integer representing the minimum possible total cost to achieve these requirements.
*/
class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1,
                          int need2) {
        long long totalCost = 0;

        // Buying separately is cheaper; item 3 is unnecessary
        if (cost1 + cost2 <= costBoth) {
            totalCost = 1LL * cost1 * need1 + 1LL * cost2 * need2;
        } else {
            // Buy item 3 first until one requirement is fulfilled
            int cnt_3 = min(need1, need2);
            totalCost = 1LL * cnt_3 * costBoth;

            need1 -= cnt_3;
            need2 -= cnt_3;

            // Type 1 is still needed; choose the cheaper of items 1 and 3
            if (need1 > 0) {
                totalCost += 1LL * need1 * min(cost1, costBoth);
            }

            // Type 2 is still needed; choose the cheaper of items 2 and 3
            else if (need2 > 0) {
                totalCost += 1LL * need2 * min(cost2, costBoth);
            }
        }

        return totalCost;
    }
};