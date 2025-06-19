
class DSU{
private:
    vector<int> parent, rank;
public:
    // O(N) time
    DSU(int n){
        for(int idx=0 ; idx<n; idx++){
            parent.push_back(idx);
            rank.push_back(1);
        }
    }

    // Path Compression
    int find(int x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    // Union by Rank
    bool unionByRank(int a , int b){
        int pa = find(a);
        int pb = find(b);

        if(pa == pb) return false;
        if(rank[pa] < rank[pb]){
            parent[pa] = pb;
            rank[pb] += rank[pa]; 
        }
        else{
            parent[pb] = pa;
            rank[pa] += rank[pb]; 
        }
        return true;
    }
};


class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size() , m = grid[0].size();
        DSU dsu(n*m);

        int island = 0;
        for(int r=0; r<n; r++){
            for(int c= 0; c<m; c++){
                if(grid[r][c] == '1' ) island++;
            }
        }

        // UP ,DOWN ,LEFT , RIGHT
        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};
        for(int r=0; r<n; r++){
            for(int c = 0; c<m; c++){
                if(grid[r][c] == '0' ) continue; // water
                int a = r * m + c;
                for(int d=0 ; d<4; d++){
                    int nr = r + dr[d];
                    int nc = c + dc[d];
                    int b = nr * m + nc;
                    if(nr>= 0 && nc >= 0 && nr<n && nc<m && grid[nr][nc] == '1'){
                        if(dsu.unionByRank(a,b)) island--;
                    }      
                }
                
            }
        }
        return island;
    }
};