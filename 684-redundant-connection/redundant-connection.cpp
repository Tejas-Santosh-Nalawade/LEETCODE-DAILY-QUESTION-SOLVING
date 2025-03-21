class Solution {
    class DSU {
    private:
        int N;
        vector<int> size;
        vector<int> representative;
    public:
        DSU(int N) {
            this->N = N;
            for (int node = 0; node < N; node++) {
                size.push_back(1);
                representative.push_back(node);
            }
        }
        int find(int node) {
            if (representative[node] == node) {
                return node;
            }
            return representative[node] = find(representative[node]);
        }
        bool doUnion(int nodeOne, int nodeTwo) {
            nodeOne = find(nodeOne);
            nodeTwo = find(nodeTwo);

            if (nodeOne == nodeTwo) {
                return 0;
            } else {
                if (size[nodeOne] > size[nodeTwo]) {
                    representative[nodeTwo] = nodeOne;
                    size[nodeOne] += size[nodeTwo];
                } else {
                    representative[nodeOne] = nodeTwo;
                    size[nodeTwo] += size[nodeOne];
                }
                return 1;
            }
        }
    };

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int N = edges.size();

        DSU dsu(N);
        for (auto edge : edges) {
            if (!dsu.doUnion(edge[0] - 1, edge[1] - 1)) {
                return edge;
            }
        }
        return {};
    }
};