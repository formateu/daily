class Solution {
public:
    using Grid = std::vector<std::vector<int>>;
    struct CoordDist {
        int d;
        int x;
        int y;

        bool operator<(const CoordDist &rhs) const {
            return this->d < rhs.d;
        }

        bool operator>(const CoordDist &rhs) const {
            return this->d > rhs.d;
        }
    };

    using PQ = std::priority_queue<CoordDist, std::vector<CoordDist>, std::greater<CoordDist>>;
    
    int minimumObstacles(Grid& grid) {
        PQ pq;
        const auto M = grid.size();
        const auto N = grid[0].size();
        std::vector<int> dist(M*N, M+N+1);
        pq.push({0,0,0});
        dist[0] = 0;

        while (!pq.empty()) {
            const auto [_, x, y] = pq.top();
            pq.pop();
            if (x+1 < M) {
                if (dist[(x+1)*N+y] > dist[x*N+y] + grid[x][y]) {
                    dist[(x+1)*N+y] = dist[x*N+y] + grid[x][y];
                    pq.push(CoordDist{dist[(x+1)*N+y], x+1, y});
                }
            }

            if (x-1 >= 0) {
                if (dist[(x-1)*N+y] > dist[x*N+y] + grid[x][y]) {
                    dist[(x-1)*N+y] = dist[x*N+y] + grid[x][y];
                    pq.push(CoordDist{dist[(x-1)*N+y], x-1, y});
                }
            }

            if (y+1 < N) {
                if (dist[(x)*N+y+1] > dist[x*N+y] + grid[x][y]) {
                    dist[(x)*N+y+1] = dist[x*N+y] + grid[x][y];
                    pq.push(CoordDist{dist[x*N+y+1], x, y+1});
                }
            }

            if (y-1 >= 0) {
                if (dist[(x)*N+y-1] > dist[x*N+y] + grid[x][y]) {
                    dist[(x)*N+y-1] = dist[x*N+y] + grid[x][y];
                    pq.push(CoordDist{dist[x*N+y-1], x, y-1});
                }
            }
        }

        return dist.back();
    }
};

static const auto k = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();