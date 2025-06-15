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
        vector<int> incoming(numCourses,0);

        // Adjacent List
        for (vector<int> &e : prerequisites) {
            int u = e[0], v = e[1];
            adj[v].push_back(u);
            incoming[u]++;

        }

        queue<int> q;
        vector<int> topo;

        for(int idx=0; idx<numCourses; idx++)
        {
            if(incoming[idx] == 0) q.push(idx);
        }

        while(q.size() !=0){
            int src  =q.front();
            q.pop();
            topo.push_back(src);

            for(int &nbr : adj[src]){
                incoming[nbr] --;
                if(incoming[nbr] == 0) q.push(nbr);
            }
        }
        if(topo.size() < numCourses) return {};
        return topo;
    }
};