class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size(); 
        int fresh = 0;
        
        queue<pair<pair<int,int>, int>> q;
        for(int r=0; r<rows; r++){
            for(int c=0; c < cols; c++)
            {
                if(grid[r][c] == 2) q.push({{r,c},0});
                else if (grid[r][c] == 1) fresh++;
            }
        }

        int timer = 0;
        
        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,1,-1};

        while(q.size() > 0 &&  fresh !=0){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int d = q.front().second;
            q.pop();

            for(int i=0; i<4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];

                // out of matrix
                if(nr<0 || nc<0 || nr >= rows || nc >= cols ) continue;

                if(grid[nr][nc] == 1){
                    grid[nr][nc] = 2; // visited rotten
                    fresh --;
                    q.push({{nr,nc},d + 1});
                    timer = d + 1;
                }

            }
        }

        if(fresh>0 ) return -1;
        return timer;




    }
};