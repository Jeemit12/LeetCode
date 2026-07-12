/*
Given an array of integers arr, replace each element with its rank.

The rank represents how large the element is. The rank has the following rules:

Rank is an integer starting from 1.
The larger the element, the larger the rank. If two elements are equal, their rank must be the same.
Rank should be as small as possible.
*/
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int, int> numToRank;
        vector<int> sortedArr(arr);
        sort(sortedArr.begin(), sortedArr.end());
        int rank = 1;
        for (int i = 0; i < sortedArr.size(); i++) {
            if (i > 0 && sortedArr[i] > sortedArr[i - 1]) {
                rank++;
            }
            numToRank[sortedArr[i]] = rank;
        }
        for (int i = 0; i < arr.size(); i++) {
            arr[i] = numToRank[arr[i]];
        }
        return arr;
    }
};