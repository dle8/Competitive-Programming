#define fi first
#define se second
typedef pair<int, int> pii;
#define sz(x) int(x.size())
class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
        queue<pii> q;
        q.push({r0, c0});
        int rows = sz(grid);
        int cols = sz(grid[0]);
        int originalColor = grid[r0][c0];
        vector<vector<int>> cgrid = grid;
        bool check[100][100];
        memset(check, false, sizeof(check));
        while (!q.empty()) {
            pii u = q.front();
            q.pop();
            if (check[u.fi][u.se]) continue;
            check[u.fi][u.se] = true;
            if (u.fi == 0 || u.fi == rows - 1 || u.se == 0 || u.se == cols - 1) {
                cgrid[u.fi][u.se] = color;
            }
            else {
                if (grid[u.fi + 1][u.se] != originalColor || grid[u.fi - 1][u.se] != originalColor || grid[u.fi][u.se + 1] != originalColor || grid[u.fi][u.se - 1] != originalColor) {
                    cgrid[u.fi][u.se] = color;
                }
            }
            if (u.fi != rows - 1 && grid[u.fi + 1][u.se] == originalColor) {
                q.push({u.fi + 1, u.se});
            }
            if (u.fi != 0 && grid[u.fi - 1][u.se] == originalColor) {
                q.push({u.fi - 1, u.se});
            }
            if (u.se != cols - 1 && grid[u.fi][u.se + 1] == originalColor) {
                q.push({u.fi, u.se + 1});
            }
            if (u.se != 0 && grid[u.fi][u.se - 1] == originalColor) {
                q.push({u.fi, u.se - 1});
            }
        }
        return cgrid;
    }
};
