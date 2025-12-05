class Solution {
    struct DSU{
        vector<int> parent;
        vector<int> size;
        
        DSU(int n){
            size.resize(n+1, 1);
            parent.resize(n+1);
            for(int i=0; i<=n ; i++) parent[i]=i;
        }
        
        int findPar(int x){
            if(x== parent[x]) return x;
            return parent[x]= findPar(parent[x]);
        }
        
        int merge(int x , int y){
            x= findPar(x); y= findPar(y);
            
            if(x==y) return 0;
            if(size[x] > size[y]) swap(x, y);
            parent[x] = y;
            size[y] += size[x];
            return 1;
        }
    };

public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        int n = matrix.size(), m= matrix[0].size();
        map<int, vector<pair<int,int>>> mp;

        for(int i=0; i<n; i++){
            for(int j=0; j<m ;j++){
                mp[matrix[i][j]].push_back({i,j});
            }
        }

        vector<vector<int>> ans(n, vector<int>(m));
        vector<int> row(n), col(m);   //storing the maxi rank in that row and col
        vector<int> rank(n+m);   //storing the maxi rank of the CC.

        for(auto &[val, indexes] : mp){
            DSU dsu(n+m+1);

            for(auto &[i, j] : indexes){
                dsu.merge(i, j + n);       //merging row and col
            }

            for(auto &[i, j]: indexes){                             
                rank[dsu.findPar(i)] = max({rank[dsu.findPar(i)] , row[i], col[j]}); //finding rank of CC 
            }                                                       //by the help of row and col.

            for(auto &[i, j]: indexes){          //new ranks
                ans[i][j] = row[i] = col[j] = rank[dsu.findPar(i)]  + 1;
            }
        }

        return ans;
    }
};