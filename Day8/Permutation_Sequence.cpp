/*
The set [1, 2, 3, ..., n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.
*/
class Solution {
public:
    string getPermutation(int n, int k) {
        int fac=1;
        vector<int> v;
        for(int i=1;i<n;i++){
            fac*=i;
            v.push_back(i);
        }
        v.push_back(n);
        string ans="";
        k=k-1;
        while(true){
            int ind=k/fac;
            ans+=to_string(v[ind]);
            v.erase(v.begin()+ind);
            if(v.size()==0) break;
            k=k%fac;
            fac=fac/v.size();
        }
        return ans;

    }
};