/*
Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.

A shift on s consists of moving the leftmost character of s to the rightmost position.

For example, if s = "abcde", then it will be "bcdea" after one shift.
*/
class Solution {
public:
    void rev(string &s,int start,int end){
        while(start<end){
            char t=s[start];
            s[start]=s[end];
            s[end]=t;
            start++;
            end--;
        }
    }
    bool rotateString(string s, string goal) {
        int n=s.length();
        if(n !=goal.length()) return false; 
        
        for(int i=0;i<n;i++){
           string a=s;
           rev(a,0,i-1);
           rev(a,i,n-1);
           rev(a,0,n-1);
           cout<<a<<" ";
           if(a==goal) return true; 
        }
        return false;
    }
};