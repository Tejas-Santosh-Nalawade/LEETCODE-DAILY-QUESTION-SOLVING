class Solution
{
public:
    bool dfs(int src, vector<vector<int>> &adj, vector<int> &vis)
    {
        if (vis[src] == 1) return true;
        if (vis[src] == 2) return false;

        vis[src] = 1; // preorder
        for (int &nbr : adj[src]){
            if(dfs(nbr, adj, vis)) return true;
        }

        vis[src] = 2; // postorder
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites){
        vector<vector<int>> adj(numCourses);

        for (vector<int> &e : prerequisites) {
            int u = e[0], v = e[1];
            adj[v].push_back(u);
        }

        vector<int>vis(numCourses, 0);

        for (int idx = 0; idx < numCourses; idx++){
            if (vis[idx] == 0){
                bool cycle = dfs(idx, adj, vis);
                if (cycle == true) return false; // cycle
            }
        }

        return true; // no cycle formed
    }
};
