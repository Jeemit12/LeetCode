/*
Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.

Return the quotient after dividing dividend by divisor.
*/
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        if (dividend == INT_MIN && divisor == 1)
            return INT_MIN;
        long dvd=labs((long) dividend);
        long dvs=labs((long) divisor);
        long i=0;
        while(dvd-dvs>=0){
            dvd-=dvs;
            i++;
        }
        if((dividend<0) ^ (divisor < 0)) return (int)-i;
        else return (int)i;
    
    }
};
// class Solution {
// public:
//     int divide(int dividend, int divisor) {
//         long dvd=(long) dividend;
//         long dvs=(long) divisor;
//         if (dividend == INT_MIN && divisor == -1)
//             return INT_MAX;
//         if (dividend == INT_MIN && divisor == 1)
//             return INT_MIN;
//         if(divisor==0) return 0;
//         int i=0;
//         if(dvd>0 && dvs>0 ){
//             while(dvd-dvs>=0){
//                 i++;
//                 dvd-=dvs;
//             }
//             return i;
//         }
//         else if(dvd<0 && dvs>0){
//             dvd=-dvd;
//             while(dvd-dvs>=0){
//                 dvd-=dvs;
//                 i++;
//             }
//             return -i;
//         }
//         else if(dvd<0 &&  dvs<0){
//             dvd=-dvd;
//             dvs=-dvs;
//             while (dvd - dvs >= 0) {
//                 dvd -= dvs;
//                 i++;
//             }
//             return i;
//         }
//         else if(dvd > 0 && dvs<0){
//             dvd=-dvd;
//             dvs=-dvs;
//             while(dvd+dvs<=0){
//                 dvd+=dvs;
//                 i++;
//             }
//             return -i;
//         }
//         else return 0;
//     }

// };