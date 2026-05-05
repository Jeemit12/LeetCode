/*
Implement pow(x, n), which calculates x raised to the power n (i.e., xn).
*/
class Solution {
public:
    double pow(double a,int n){
        double b=a;
        for(int i=0;i<n-1;i++){
            a*=b;
            cout<<a<<" ";
        }
        return a;
    }
    double myPow(double x, int n) {
        long long N=n;
        if(N<0){
            x=1/x;
            N=-N;
        }
        double result=1;
        while(N>0){
            if(N%2==1){
                result*=x;

            }
            x*=x;
            N/=2;
        }
        return result;
    }
};
// class Solution {
// public:
//     double pow(double a,int n){
//         double b=a;
//         for(int i=0;i<n-1;i++){
//             a*=b;
//             cout<<a<<" ";
//         }
//         return a;
//     }
//     double myPow(double x, int n) {
//         if(n==0) return 1;
//         if(x==0) return 0;
//         if(n<0){
//             return 1/pow(x,abs(n));
//         }
//         else{
//             return pow(x,n);
//         }
//     }
// };