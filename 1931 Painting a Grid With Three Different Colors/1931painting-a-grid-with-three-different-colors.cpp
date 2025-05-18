class Solution {
public:
    int colorTheGrid(int m, int n) {
        static constexpr int mod = 1000000007;
        const std::size_t V = 3 * (1 << (m-1));
        std::vector<bool> adj(V*V, true);
        std::vector<std::string> vertices(V);
        // O(2^m)
        generateWithPrefix("", vertices, 0, m);

        // O(m*2^(2m))
        for (int i = 0; i < vertices.size(); ++i) {
            for (int j = 0; j < vertices.size(); ++j) {
                for (int k = 0; k < m; ++k) {
                    if (vertices[i][k] == vertices[j][k]) {
                        adj[i*V + j] = false;
                        break;
                    }
                }
            }
        }

        std::vector<int> dp(n*V, 0); 
        for (int v = 0; v < V; ++v) {
            dp[v] = 1;
        }

        // O(n*2^m)
        for (int j = 1; j < n; ++j) {
            for (int v1 = 0; v1 < V; ++v1) {
                for (int v2 = 0; v2 < V; ++v2) {
                    if (adj[v1*V + v2]) {
                        dp[j*V + v1] = (dp[(j-1)*V +v2] + dp[j*V + v1]) % mod;
                    }
                }
            }
        }


        int result = 0;
        for (int i = 0; i < V; ++i) {
            result = (result + dp[(n-1)*V + i]) % mod;
        }

        return result;
    }

    int generateWithPrefix(std::string prefix, std::vector<std::string> &out, int ind, int m) {
        if (prefix.size() == m) {
            out[ind++] = prefix;
            return ind;
        }

        for (char c = '0'; c <= '2'; ++c) {
            if (prefix.empty() || c != prefix.back()) {
                ind = generateWithPrefix(prefix+c, out, ind, m);
            }
        }

        return ind;
    }
};