class Solution {
public:
    vector<int> parent;
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    void unite(int a, int b) {
        int ra = find(a);
        int rb = find(b);
        if (ra == rb) return;
        if (ra < rb) {
            parent[rb] = ra;
        } else {
            parent[ra] = rb;
        }
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        parent.resize(26);
        for (int i = 0; i < 26; ++i) {
            parent[i] = i;
        }

        
        for (int i = 0; i < (int)s1.size(); ++i) {
            int x = s1[i] - 'a';
            int y = s2[i] - 'a';
            unite(x, y);
        }

        
        string ans = baseStr;
        for (int i = 0; i < (int)baseStr.size(); ++i) {
            int idx = baseStr[i] - 'a';
            int root = find(idx);
            ans[i] = char(root + 'a');
        }
        return ans;
    }
};