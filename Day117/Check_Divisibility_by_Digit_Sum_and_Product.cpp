/*
ou are given a positive integer n. Determine whether n is divisible by the sum of the following two values:

The digit sum of n (the sum of its digits).

The digit product of n (the product of its digits).

Return true if n is divisible by this sum; otherwise, return false.
*/
class Solution {
public:
    bool checkDivisibility(int n) {
        int p=1,s=0;
        int x=n;
        while(n>0){
            int a=n%10;
            p*=a;
            s+=a;
            n/=10;
        }
        if(x%(p+s)==0) return true;
        else return false;
    }
};