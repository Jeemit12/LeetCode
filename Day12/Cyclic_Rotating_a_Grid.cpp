/*
You are given an m x n integer matrix grid​​​, where m and n are both even integers, and an integer k.

The matrix is composed of several layers, which is shown in the below image, where each color is its own layer:
A cyclic rotation of the matrix is done by cyclically rotating each layer in the matrix. To cyclically rotate a layer once, each element in the layer will take the place of the adjacent element in the counter-clockwise direction. An example rotation is shown below:
Return the matrix after applying k cyclic rotations to it.
*/
class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        int layers=min(m,n)/2;
        for(int i=0;i<layers;i++){
            int top=i;
            int bottom=m-1-i;
            int left=i;
            int right=n-1-i;
            vector<int> v;
            for(int j=left;j<=right;j++){
                v.push_back(grid[top][j]);
            }
            for(int j=top+1;j<=bottom;j++){
                v.push_back(grid[j][right]);
            }
            for(int j=right-1;j>=left;j--){
                v.push_back(grid[bottom][j]);
            }
            for(int j=bottom-1;j>top;j--){
                v.push_back(grid[j][left]);
            }
            int rot=k%v.size();
            rotate(v.begin(),v.begin()+rot,v.end());
            int idx=0;
             for(int j=left;j<=right;j++){
                grid[top][j]=v[idx++];
            }
            for(int j=top+1;j<=bottom;j++){
                grid[j][right]=v[idx++];
            }
            for(int j=right-1;j>=left;j--){
                grid[bottom][j]=v[idx++];
            }
            for(int j=bottom-1;j>top;j--){
                grid[j][left]=v[idx++];
            }
        }
        return grid;
    }
};