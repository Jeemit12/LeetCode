/*
Given a 2D grid of size m x n and an integer k. You need to shift the grid k times.

In one shift operation:

Element at grid[i][j] moves to grid[i][j + 1].
Element at grid[i][n - 1] moves to grid[i + 1][0].
Element at grid[m - 1][n - 1] moves to grid[0][0].
Return the 2D grid after applying shift operation k times.
*/
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        int total=m*n;
        k=k%total;
        auto rev= [&](int i,int j){
            while(i<j){
                swap(grid[i/n][i%n],grid[j/n][j%n]);
                i++;
                j--;
            }
        };
        rev(0,total-1);
        rev(0,k-1);
        rev(k,total-1);
        return grid;

    }
};