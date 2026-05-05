/*
You are given a 0-indexed circular string array words and a string target. A circular array means that the array's end connects to the array's beginning.

Formally, the next element of words[i] is words[(i + 1) % n] and the previous element of words[i] is words[(i - 1 + n) % n], where n is the length of words.
Starting from startIndex, you can move to either the next word or the previous word with 1 step at a time.

Return the shortest distance needed to reach the string target. If the string target does not exist in words, return -1.
*/

class Solution {
public:
    int min(int a,int b){
        if(a<b) return a;
        else return b;
    }
    int minval(int a,vector<int> arr,int n){
        int temp=INT_MAX;
        for(int i=0;i<arr.size();i++){
            int b=abs(a-arr[i]);
            int c=n-b;
            temp=min(temp,min(c,b));
    }
        return temp;
    }
    int closestTarget(vector<string>& words, string target, int startIndex) {
        vector<int> val;
        for(int i=0;i<words.size();i++){
            if(target==words[i]){
                val.push_back(i);
            }
        }
        if(val.size()==0) return -1;
        else{
            return minval(startIndex,val,words.size());
        }

        
    }
};