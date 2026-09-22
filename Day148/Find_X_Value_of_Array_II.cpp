/*
You are given an array of positive integers nums and a positive integer k. You are also given a 2D array queries, where queries[i] = [indexi, valuei, starti, xi].

You are allowed to perform an operation once on nums, where you can remove any suffix from nums such that nums remains non-empty.

The x-value of nums for a given x is defined as the number of ways to perform this operation so that the product of the remaining elements leaves a remainder of x modulo k.

For each query in queries you need to determine the x-value of nums for xi after performing the following actions:

Update nums[indexi] to valuei. Only this step persists for the rest of the queries.
Remove the prefix nums[0..(starti - 1)] (where nums[0..(-1)] will be used to represent the empty prefix).
Return an array result of size queries.length where result[i] is the answer for the ith query.

A prefix of an array is a subarray that starts from the beginning of the array and extends to any point within it.

A suffix of an array is a subarray that starts at any point within the array and extends to the end of the array.

Note that the prefix and suffix to be chosen for the operation can be empty.

Note that x-value has a different definition in this version.
*/
class Solution {
    struct Info {
        vector<int> ways;
        int whole;

        Info(int k) : ways(k, 0), whole(1) {}
    };

    struct SegmentTree {
        int size;
        int mod;
        vector<Info> tree;

        SegmentTree(vector<int>& nums, int k) {
            mod = k;
            size = 1;

            while (size < nums.size()) {
                size <<= 1;
            }

            tree.reserve(size * 2);

            for (int i = 0; i < size * 2; i++) {
                tree.emplace_back(k);
            }

            for (int i = 0; i < nums.size(); i++) {
                int rem = nums[i] % k;

                tree[size + i].ways[rem] = 1;
                tree[size + i].whole = rem;
            }

            for (int i = size - 1; i > 0; i--) {
                tree[i] = combine(
                    tree[i << 1],
                    tree[i << 1 | 1]
                );
            }
        }

        Info combine(const Info& left, const Info& right) {
            Info merged(mod);

            for (int r = 0; r < mod; r++) {
                merged.ways[r] = left.ways[r];
            }

            for (int r = 0; r < mod; r++) {
                if (right.ways[r] == 0) {
                    continue;
                }

                int newRem = (left.whole * r) % mod;
                merged.ways[newRem] += right.ways[r];
            }

            merged.whole = (left.whole * right.whole) % mod;

            return merged;
        }

        void update(int index, int value) {
            int pos = size + index;
            int rem = value % mod;

            fill(tree[pos].ways.begin(),
                 tree[pos].ways.end(), 0);

            tree[pos].ways[rem] = 1;
            tree[pos].whole = rem;

            pos >>= 1;

            while (pos > 0) {
                tree[pos] = combine(
                    tree[pos << 1],
                    tree[pos << 1 | 1]
                );

                pos >>= 1;
            }
        }

        Info query(int left, int right) {
            Info leftPart(mod);
            Info rightPart(mod);

            left += size;
            right += size;

            while (left < right) {
                if (left & 1) {
                    leftPart = combine(leftPart, tree[left]);
                    left++;
                }

                if (right & 1) {
                    right--;
                    rightPart = combine(tree[right], rightPart);
                }

                left >>= 1;
                right >>= 1;
            }

            return combine(leftPart, rightPart);
        }
    };

public:
    vector<int> resultArray(
        vector<int>& nums,
        int k,
        vector<vector<int>>& queries
    ) {
        SegmentTree tree(nums, k);
        vector<int> answer;

        for (auto& q : queries) {
            tree.update(q[0], q[1]);

            Info result = tree.query(q[2], nums.size());
            answer.push_back(result.ways[q[3]]);
        }

        return answer;
    }
};