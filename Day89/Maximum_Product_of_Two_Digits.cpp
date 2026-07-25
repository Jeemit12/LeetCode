/*
You are given a positive integer n.

Return the maximum product of any two digits in n.

Note: You may use the same digit twice if it appears more than once in n.
*/
class Solution {
public:
    int maxProduct(int n) {
        int mx1=0;
        int mx2=0;
        while(n>0){
            int a=n%10;
            n/=10;
            if(a>mx1){
                mx2=mx1;
                mx1=a;
            }
            else if(a>mx2){
                mx2=a;
            }
        }
        return mx1*mx2;
    }
};