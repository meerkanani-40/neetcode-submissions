class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty()){
            return 0;
        }

        int n = grid.size();
        int m = grid[0].size();

        int totalOranges = 0;
        int rottenOranges = 0;
        int mins = 0;

        queue<pair<int, int>> rotten;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] != 0){
                    totalOranges++;
                }

                if(grid[i][j] == 2){
                    rotten.push({i, j});
                }
            }
        }

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        while(!rotten.empty()){
            int k = rotten.size();
            rottenOranges += k;

            while(k--){
                int x = rotten.front().first;
                int y = rotten.front().second;
                rotten.pop();

                for(int i = 0; i < 4; i++){
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if(nx < n && ny < m && nx >= 0 && ny >= 0 && grid[nx][ny] == 1){
                        rotten.push({nx, ny});
                        grid[nx][ny] = 2;
                    }
                }
            }
            if(!rotten.empty()){
                mins++;
            }
        }

        return rottenOranges == totalOranges ? mins : -1;
    }
};
