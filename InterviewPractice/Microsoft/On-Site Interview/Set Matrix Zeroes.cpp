// https://leetcode.com/problems/set-matrix-zeroes/

#define sz(x) int(x.size())
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> cols;
        set<int> rows;
        for (int i = 0; i < sz(matrix); i++) {
            for (int j = 0; j < sz(matrix[i]); j++) {
                if (matrix[i][j] == 0) {
                    cols.insert(j);
                    rows.insert(i);
                }
            }
        }
        for (int i = 0; i < sz(matrix); i++) {
            for (int j = 0; j < sz(matrix[i]); j++) {
                if (rows.find(i) != rows.end() || cols.find(j) != cols.end()) matrix[i][j] = 0;
            }
        }
    }
};
