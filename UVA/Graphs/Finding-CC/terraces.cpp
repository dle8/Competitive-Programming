#include <bits/stdc++.h>
using namespace std;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

bool inBound(int a, int b) {
    return (a >= 0 && a < b);
}

void dfs(int x, int y, int h, int w, vector<vector<bool>> &visited, const vector<vector<int>> &grid, int &minNeighbor, int &countCell) {
    visited[x][y] = true;
    ++countCell;
    for (int i = 0; i < 4; ++i) {
        int neighborX = x + dr[i];
        int neighborY = y + dc[i];
        if (inBound(neighborX, h) && inBound(neighborY, w)) {
            if (grid[x][y] == grid[neighborX][neighborY] && !visited[neighborX][neighborY]) {
                dfs(neighborX, neighborY, h, w, visited, grid, minNeighbor, countCell);
            } else if (grid[x][y] != grid[neighborX][neighborY]) {
                minNeighbor = min(minNeighbor, grid[neighborX][neighborY]);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    int h, w;
    cin >> w >> h;
    vector<vector<int>> grid(h, vector<int>{});
    vector<vector<bool>> visited(h, vector<bool>{});
    for (int i = 0; i < h; ++i) {
        grid[i].assign(w, 0);
        visited[i].assign(w, false);
    }
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> grid[i][j];
        }
    }
    int res = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (!visited[i][j]) {
                // for each scc find the smallest neighbor cell value
                int minNeighbor = grid[i][j], countCell = 0;
                dfs(i, j, h, w, visited, grid, minNeighbor, countCell);
                if (minNeighbor == grid[i][j]) {
//                    cout << i << " " << j << " " << minNeighbor << " " << countCell << '\n';
                    res += countCell;
                }
            }
        }
    }
    cout << res;
    return 0;
}