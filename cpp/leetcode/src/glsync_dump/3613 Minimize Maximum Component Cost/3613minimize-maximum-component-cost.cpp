class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges, int k) {
        if (k == n) {
            return 0;
        }
        std::sort(edges.begin(), edges.end(), [](const auto &e1, const auto &e2) {
           return e1[2] < e2[2]; 
        });

        std::vector<int> parent(n);
        std::vector<int> sz(n, 1);
        std::iota(parent.begin(), parent.end(), 0);
        int components = n;
        int result = 0;
        for (const auto &e : edges) {
            const int u = e[0];
            const int v = e[1];
            const int w = e[2];
            if (find(u, parent) != find(v, parent)) {
                unite(u, v, parent, sz);
                --components;
                result = w;
                if (components == k) break;
            }
        }

        return result;
    }

    int find(int u, std::vector<int> &parent) {
        if (parent[u] != u) {
            parent[u] = find(parent[u], parent);
        }

        return parent[u];
    }

    void unite(int u, int v, std::vector<int> &parent, std::vector<int> &sz) {
        int ru = find(u, parent);
        int rv = find(v, parent);
        
        if (ru == rv) return;
        if (sz[ru] < sz[rv]) {
            std::swap(ru, rv);
        }
        parent[rv] = ru;
        sz[ru] += rv;
        
    }
};