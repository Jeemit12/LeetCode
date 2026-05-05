/*
An integer x is a good if after rotating each digit individually by 180 degrees, we get a valid number that is different from x. Each digit must be rotated - we cannot choose to leave it alone.

A number is valid if each digit remains a digit after rotation. For example:

0, 1, and 8 rotate to themselves,
2 and 5 rotate to each other (in this case they are rotated in a different direction, in other words, 2 or 5 gets mirrored),
6 and 9 rotate to each other, and
the rest of the numbers do not rotate to any other number and become invalid.
Given an integer n, return the number of good integers in the range [1, n].
*/
class Solution {
public:
    int rotatedDigits(int n) {
        int a=0;
        for(int i=1;i<=n;i++){
            int num=i;
            bool isvalid=true;
            bool canChange=false;
            while(num>0){
                int j=num%10;
                if(j==3 || j==4 || j==7){
                    isvalid=false;
                    break;
                }
                if( j==2 || j==5 || j==6 || j==9){
                    canChange=true;
                }
                num=num/10;
                
            }
            if( isvalid && canChange){
                    a++;
                }

        }
        return a;       
    }
};