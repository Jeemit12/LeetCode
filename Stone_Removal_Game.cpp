/*
Alice and Bob are playing a game where they take turns removing stones from a pile, with Alice going first.

Alice starts by removing exactly 10 stones on her first turn.
For each subsequent turn, each player removes exactly 1 fewer stone than the previous opponent.
The player who cannot make a move loses the game.

Given a positive integer n, return true if Alice wins the game and false otherwise.
*/
class Solution {
public:
    bool canAliceWin(int n) {
        int k = (21 - sqrt(441 - 8 * n)) / 2;
        return k % 2 == 1;
    }
};