/*
You are given a palindromic string s.

Return the lexicographically smallest palindromic permutation of s.
*/
class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.length();
        int mid=n/2;
        sort(s.begin(),s.begin()+mid);
        for(int i=mid;i<n;i++){
            s[i]=s[n-i-1];
        }    
        return s;
    }
};