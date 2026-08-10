/*
Alice and Bob take turns playing a game, with Alice starting first.

Initially, there are n stones in a pile. On each player's turn, that player makes a move consisting of removing any non-zero square number of stones in the pile.

Also, if a player cannot make a move, he/she loses the game.

Given a positive integer n, return true if and only if Alice wins the game otherwise return false, assuming both players play optimally.
*/
class Solution {
public:
    bool findScore(vector<int>&dp,int n)
    {
        if(n==0) return false;
        if(dp[n]!=-1) return dp[n];
        for(int i=1;i*i<=n;i++)
        {
            int stone=i*i;
            if(findScore(dp,n-stone)==false) return dp[n]=true;
        }
        return dp[n]=false;
    }
    bool winnerSquareGame(int n) {
        vector<int>dp(n+1,-1);
        return findScore(dp,n);
    }
};