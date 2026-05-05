/*
You are given an integer array height of 
length n. There are n vertical lines drawn 
such that the two endpoints of the ith line are 
(i, 0) and (i, height[i]).
Find two lines that together with the x-axis form 
a container, such that the container contains the most water.
Return the maximum amount of water a container can store.
Notice that you may not slant the container.
*/
int min(int a,int b){
    if(a<b) return a;
    else return b;
}
class Solution {
public:
    int maxArea(vector<int>& height) {
        // int n=height.size();
        // int area=0;
        // int temp=0;
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         temp=(j-i)*min(height[j],height[i]);
        //         if(area<temp) area=temp;
        //     }
        // }
        int n=height.size();
        int l=0;
        int r=n-1;
        int area=0;
        int temp=0;
        while(l<r){
           temp=(r-l)*min(height[l],height[r]);
           if(area<temp) area=temp;
           if(height[l]<height[r]) l++;
           else r--;
        }
        return area;
    }
};