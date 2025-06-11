class Solution {
public:
    bool dfs(int src, int dest, vector<vector<int>>&adj, vector<bool>&vis)
    {
        if(src == dest){
            return true;
        }
        if(vis[src]) return false;

        vis[src]  = true;

        for(int &nbr: adj[src])
        {
            if(dfs(nbr,dest, adj,vis)){
                return true;
            }
        }
        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // edge list is provide first convert to adjacency list
        vector<vector<int>> adj(n);
        
        for(auto &e : edges)
        {
            int u = e[0] , v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);

        }
        vector<bool>vis(n,false);
        return dfs(source, destination, adj, vis);
    }
};