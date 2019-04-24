// https://leetcode.com/problems/battleships-in-a-board/

#define sz(x) int(x.size())
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int cnt = 0;
        for (int i = 0; i < sz(board); i++) {
            for (int j = 0; j < sz(board[0]); j++) {
                if (board[i][j] == 'X') {
                    if (i != 0 && board[i - 1][j] == 'X') continue;
                    if (j != 0 && board[i][j - 1] == 'X') continue;
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
