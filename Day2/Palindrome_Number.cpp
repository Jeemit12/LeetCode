/*
Given an integer x, return 
true if x is a palindrome, and false otherwise.
*/
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;
        int n=0,a=x;
        while(a){
            if(n > INT_MAX / 10 ) return false;
            n = n * 10 + a % 10;
            a /= 10;
        }
        return n==x; 
    }
};