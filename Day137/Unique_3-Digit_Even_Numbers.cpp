/*
You are given an array of digits called digits. Your task is to determine the number of distinct three-digit even numbers that can be formed using these digits.

Note: Each copy of a digit can only be used once per number, and there may not be leading zeros.
*/
class Solution {
public:
    int totalNumbers(auto& digits) {
        int f[10] = {0};
        int res = 0;

        for (auto& d : digits)
            f[d]++;

        for (int i = 1; i < 10; i++) 
            for (int j = 0; j < 10; j++) 
                for (int k = 0; k < 9; k += 2) 
                    res += f[i] > 0 &&
                           f[j] > (i == j) &&
                           f[k] > (i == k) + (j == k);
        

        return res;
    }
};