/*
A cinema has n rows of seats, numbered from 1 to n. Each row has 10 seats, numbered from 1 to 10.

You are given a 2D integer array reservedSeats, where reservedSeats[i] = [rowi, seati] means that seat seati in row rowi is already reserved.

A four-person group must be assigned to four seats in the same row. The group can be seated in one of the following seat blocks:

seats 2, 3, 4, 5
seats 4, 5, 6, 7
seats 6, 7, 8, 9
A block can be used only if none of its seats are reserved. Each seat can be assigned to at most one group.

Return an integer denoting the maximum number of four-person groups that can be assigned.
*/
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int left = 0b11110000;
        int middle = 0b11000011;
        int right = 0b00001111;

        unordered_map<int, int> occupied;
        for (const vector<int>& seat : reservedSeats) {
            if (seat[1] >= 2 && seat[1] <= 9) {
                occupied[seat[0]] |= (1 << (seat[1] - 2));
            }
        }

        int ans = (n - occupied.size()) * 2;
        for (auto& [row, bitmask] : occupied) {
            if (((bitmask | left) == left) || ((bitmask | middle) == middle) ||
                ((bitmask | right) == right)) {
                ++ans;
            }
        }
        return ans;
    }
};