/*
You are given an integer n.

Return the total number of commas used when writing all integers from [1, n] (inclusive) in standard number formatting.

In standard formatting:

A comma is inserted after every three digits from the right.
Numbers with fewer than 4 digits contain no commas.
*/
class Solution {
public:
    long long countCommas(long long n) {
        if(n<1000) return 0;
        else if(n<1000000) return n-999;
        else if(n<1000000000) return (n-999)+(n-999999);
        else if(n<1000000000000LL) return (n-999)+(n-999999)+(n-999999999);
        else if (n<1000000000000000)return (n-999)+(n-999999)+(n-999999999)+(n-999999999999LL);
        else return (n-999)+(n-999999)+(n-999999999)+(n-999999999999LL)+(n-999999999999999LL);
    }
};