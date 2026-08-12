class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        queue<pair<int, int>> q;
        int count = 0;

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        int n = grid.size();
        int m = grid[0].size();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1'){
                    count++;
                    q.push({i, j});
                    grid[i][j] = '0';

                    while(!q.empty()){
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();

                        for(int i = 0; i < 4; i++){
                            int nx = x + dx[i];
                            int ny = y + dy[i];

                            if(nx < n && ny < m && nx >= 0 && ny >= 0 && grid[nx][ny] == '1'){
                                grid[nx][ny] = '0';
                                q.push({nx, ny});
                            }
                        }
                    }
                }
            }
        }

        return count;
    }
};
