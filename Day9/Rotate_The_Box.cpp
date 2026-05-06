/*
You are given an m x n matrix of characters boxGrid representing a side-view of a box. Each cell of the box is one of the following:

A stone '#'
A stationary obstacle '*'
Empty '.'
The box is rotated 90 degrees clockwise, causing some of the stones to fall due to gravity. Each stone falls down until it lands on an obstacle, another stone, or the bottom of the box. Gravity does not affect the obstacles' positions, and the inertia from the box's rotation does not affect the stones' horizontal positions.

It is guaranteed that each stone in boxGrid rests on an obstacle, another stone, or the bottom of the box.

Return an n x m matrix representing the box after the rotation described above.
*/
class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m=boxGrid.size();
        int n=boxGrid[0].size();

        for(int i=0;i<m;i++){
            int e=n-1;
            for(int j=n-1;j>=0;j--){
                if(boxGrid[i][j]=='*'){
                    e=j-1;
                }
                else if(boxGrid[i][j]=='#'){
                    swap(boxGrid[i][j],boxGrid[i][e]);
                    e--;
                }
            }
        }
        vector<vector<char>> ans(n,vector<char>(m));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans[j][m-1-i]=boxGrid[i][j];
            }
        }
        return ans;

    }
};