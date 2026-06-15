class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        //{{row,col},time}
        queue<pair<pair<int, int>, int>> q;
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // Pushing the initial Rotten ones into the queue.
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = true;
                }
            }
        }
        int tm = 0;
        // A neat trick to move in the 4 directions from a cell.
        int drow[] = {-1, 0, +1, 0};
        int dcol[] = {0, +1, 0, -1};
        // up,right,down,left.
        /*
        For up (row-1,col)
        For right (row,col+1)
        For bottom (row+1,col)
        For left (row,col-1)
        */
        while (q.size() > 0) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            tm = max(t, tm);
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                // Check validity of each neighbour.
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    vis[nrow][ncol] == false && grid[nrow][ncol] == 1) {
                    q.push({{nrow, ncol}, t + 1});
                    vis[nrow][ncol] = true;
                }
            }
        }

        // Check still any cell is unvisited and it contains a fresh orange then
        // return -1
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j] == false && grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return tm;
    }
};