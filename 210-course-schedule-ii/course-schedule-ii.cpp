class Solution {
public:
    int topoIdx;
    bool dfs(int src, vector<vector<int>>& adj, vector<int>&vis, vector<int> &topo){
        vis[src] = 1;
        for(int nbr: adj[src]){
            if(vis[nbr] == 1) return true;
            if(vis[nbr] == 0){
                if(dfs(nbr, adj, vis, topo))
                {
                    return true;
                }
            } 
        }
        vis[src] = 2;
        topo[topoIdx--] = src;
        return false;
    }


    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        // Adjacent List
        for (vector<int> &e : prerequisites) {
            int u = e[0], v = e[1];
            adj[v].push_back(u);
        }

        vector<int> vis(numCourses, 0);
        vector<int> topo(numCourses);
        topoIdx = numCourses -1;   
        for(int idx = 0; idx<numCourses; idx++)
        {
            if(!vis[idx]){
                bool cycle =dfs(idx ,adj ,vis, topo);
                if(cycle) return {};
            } 
        }
        return topo;
    }
};