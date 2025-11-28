class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        std::vector<std::vector<int>> adjList(n);


        for (const auto &e: edges) {
            adjList[e.front()].emplace_back(e.back());
            adjList[e.back()].emplace_back(e.front());
        }

        int result = 0;
        auto r = dfs(-1, 0, adjList, values, result, k);
        if (r % k == 0) {
            ++result;
        }

        return result;
    }

    long long dfs(int u, int v, const auto &adjList, const auto &values, int &result, int k) {
        long long myCount = static_cast<long long>(values[v]);
        for (const auto &n: adjList[v]) {
            if (n != u) {
                auto childRes = dfs(v, n, adjList, values, result, k);
                if (childRes % k == 0) {
                    ++result;
                } else {
                    myCount += childRes;
                }
            }
        }

        return myCount;
    }
};