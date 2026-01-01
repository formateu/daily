class Solution {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int m1 = calculateLongestPath(edges1);
        int m2 = calculateLongestPath(edges2);
        return std::max({m1, m2, (m1+1)/2 + (m2+1)/2 + 1});
    }

    int calculateLongestPath(const std::vector<std::vector<int>>& edges) {
        std::vector<std::vector<int>> adj(edges.size() + 1);
        std::vector<int> deg(edges.size()+1, 0);

        for (const auto &e: edges) {
            const auto v1 = e.front();
            const auto v2 = e.back();
            ++deg[v1];
            ++deg[v2];
        }

        for (int i = 0 ; i < adj.size(); ++i) {
            adj[i].reserve(deg[i]);
        }

        // O(E)
        for (const auto &e: edges) {
            const auto v1 = e.front();
            const auto v2 = e.back();

            adj[v1].emplace_back(v2);
            adj[v2].emplace_back(v1);
        }

        return getDiameterLength(adj);
    }

    std::pair<int, int> longestPathFromVertex(int node, const std::vector<std::vector<int>> &adj) {
        int maxV = node;
        std::vector<int> dist(adj.size(), -1);
        std::vector<int> queue;
        queue.emplace_back(node);
        dist[node] = 0;

        while (!queue.empty()) {
            const int n = queue.back();
            queue.pop_back();

            if (dist[n] > dist[maxV]) {
                maxV = n;
            }

            for (const auto &v: adj[n]) {
                if (dist[v] == -1) {
                    dist[v] = dist[n] + 1;
                    queue.emplace_back(v);

                    if (dist[v] > dist[maxV]) {
                        maxV = v;
                    }
                }
            }
        }

        return {maxV, dist[maxV]};
    }

    int getDiameterLength(const std::vector<std::vector<int>> &adj) {
        auto [l1, _] = longestPathFromVertex(0, adj);
        auto [l2, diameterLength] = longestPathFromVertex(l1, adj);

        return diameterLength;
    }

};