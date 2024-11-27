class Solution {
public:
    using Graph = std::unordered_map<int, std::unordered_set<int>>;
    using iPair = std::pair<int, int>;
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        Graph graph(n);

        // init
        for (int i = 0; i < n-1; ++i) {
            if (!graph.contains(i)) {
                graph.emplace(i, std::unordered_set<int>{i+1});
            } else {
                graph[i].emplace(i+1);
            }
        }

        graph.emplace(n-1, std::unordered_set<int>());

        std::vector<int> result;
        for (const auto &q : queries) {
            const auto &from = q[0];
            const auto &to = q[1];
            graph[from].emplace(to);
            result.emplace_back(shortestPath(graph));
        }

        return result;
    }

    int shortestPath(Graph &graph) {
        std::priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
        vector<int> dist(graph.size(), graph.size()+1);
        pq.push({0, 0});
        dist[0] = 0;

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();
            for (const auto &v : graph[u]) {
                if (dist[v] > dist[u] + 1) {
                    dist[v] = dist[u] + 1;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist.back();
    }
};