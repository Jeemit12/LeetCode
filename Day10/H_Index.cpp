/*
Given an array of integers citations where citations[i] is the number of citations a researcher received for their ith paper, return the researcher's h-index.

According to the definition of h-index on Wikipedia: The h-index is defined as the maximum value of h such that the given researcher has published at least h papers that have each been cited at least h times.
*/
class Solution {
public:
    int hIndex(vector<int>& citations) {

        int n=citations.size();
        for(int h=n;h>=0;h--){
            int count=0;
            for(int i=0;i<n;i++){
                if(citations[i]>=h){
                    count++;
                }
            }
            if(count>=h) return h;
        }
        return 0;
        
    }
};