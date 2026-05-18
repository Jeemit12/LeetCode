/*
Given an array of integers arr, you are initially positioned at the first index of the array.

In one step you can jump from index i to index:

i + 1 where: i + 1 < arr.length.
i - 1 where: i - 1 >= 0.
j where: arr[i] == arr[j] and i != j.
Return the minimum number of steps to reach the last index of the array.

Notice that you can not jump outside of the array at any time.
*/
class Solution {
public:
    int minJumps(vector<int>& arr) {
        if(arr.size()==1) return 0;
        if(arr[0]==arr[arr.size()-1]) return 1;
        int n=arr.size();
        int steps=0;
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<n;i++){
            mp[arr[i]].push_back(i);
        }
        queue<int> q;
        q.push(0);
        vector<bool> visited(n,false);
        visited[0]=true;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int temp=q.front();
                q.pop();
                if(temp==n-1) return steps;
                int x=temp+1;
                int y=temp-1;
                if(x>=0 && x<n && !visited[x]){
                    q.push(x);
                    visited[x]=true;
                }
                if(y>=0 && y<n && !visited[y]){
                    q.push(y);
                    visited[y]=true;
                }
                for(auto j:mp[arr[temp]]){
                   if(!visited[j]){
                    q.push(j);
                    visited[j]=true;
                   } 
                }
                mp[arr[temp]].clear();
            }
            steps++;
        }
        return -1;        
    }
};
