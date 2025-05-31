class Solution {
public:
    int n;                          
    vector<int> flat;              
    vector<int> bestDepth;        
    int bestSteps;                
    const int INF = 1e9;

    void dfs(int pos, int depth) {
        if (depth >= bestSteps) return;

        if (pos == n * n - 1) {
            bestSteps = depth;
            return;
        }

        for (int dice = 1; dice <= 6; ++dice) {
            int nxt = pos + dice;
            if (nxt >= n * n) break;  
            if (flat[nxt] != -1) {
                nxt = flat[nxt] - 1;
            }

            if (depth + 1 >= bestDepth[nxt]) {
                continue;
            }

            bestDepth[nxt] = depth + 1;
            dfs(nxt, depth + 1);
        }
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        n = board.size();
        flat.clear();
        flat.reserve(n * n);
        bestDepth.assign(n * n, INF);
        bestSteps = INF;

        bool leftToRight = true;
        for (int i = n - 1; i >= 0; --i) {
            if (leftToRight) {
                for (int j = 0; j < n; ++j) {
                    flat.push_back(board[i][j]);
                }
            } else {
                for (int j = n - 1; j >= 0; --j) {
                    flat.push_back(board[i][j]);
                }
            }
            leftToRight = !leftToRight;
        }

        bestDepth[0] = 0;
        dfs(0, 0);

        return (bestSteps == INF) ? -1 : bestSteps;
    }
};