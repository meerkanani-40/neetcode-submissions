class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int, pair<int, int>>> q;

        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0){
                    q.push({0, {i, j}});
                }
            }
        }

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        while(!q.empty()){
            int dis = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;
            q.pop();

            for(int i = 0; i < 4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx < m && ny < n && nx >= 0 && ny >= 0 && grid[nx][ny] != -1){
                    if(dis+1 < grid[nx][ny]){
                        grid[nx][ny] = dis+1;
                        q.push({grid[nx][ny], {nx, ny}});
                    }
                }
            }
        }
    }
};
