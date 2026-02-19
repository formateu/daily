class Solution {
public:
    struct CoordDistTime {
        int t;
        int x;
        int y;

        bool operator>(const CoordDistTime &rhs) const {
            return this->t > rhs.t;
        }
    };

    using PQ = std::priority_queue<CoordDistTime, std::vector<CoordDistTime>, std::greater<CoordDistTime>>;

    int minimumTime(vector<vector<int>>& grid) {
        if (grid[0][1] > 1 && grid[1][0] > 1) {
            return -1;
        }    
        PQ pq;
        const int M = grid.size();
        const int N = grid[0].size();
        std::vector<int> dist(M*N, std::numeric_limits<int>::max());

        pq.push(CoordDistTime{0, 0, 0});
        dist[0] = 0;

        while (!pq.empty()) {
            const auto [t, x, y] = pq.top();
            pq.pop();

            if (x == M - 1 && y == N - 1) {
                return t;
            }

            if (x+1 < M) {
                const int w = (grid[x+1][y] - t) % 2 ? 0 : 1;
                const int t1 = std::max(t + 1, grid[x+1][y] + w); 
                if (dist[(x+1)*N + y] > t1) {
                    dist[(x+1)*N + y] = t1;
                    pq.push(CoordDistTime{t1, x+1, y});
                }
            }
            
            if (x-1 >= 0) {
                const int w = (grid[x-1][y] - t) % 2 ? 0 : 1;
                const int t1 = std::max(t + 1, grid[x-1][y] + w); 
                if (dist[(x-1)*N + y] > t1) {
                    dist[(x-1)*N + y] = t1;
                    pq.push(CoordDistTime{t1, x-1, y });
                }
            }

            if (y+1 < N) {
                const int w = (grid[x][y+1] - t) % 2 ? 0 : 1;
                const int t1 = std::max(t + 1, grid[x][y+1] + w);
                if (dist[x*N + y+1] > t1) {
                    dist[x*N + y+1] = t1;
                    pq.push(CoordDistTime{t1, x, y+1});
                }
            }

            if (y-1 >= 0) {
                const int w = (grid[x][y-1] - t) % 2 ? 0 : 1;
                const int t1 = std::max(t + 1, grid[x][y-1] + w);
                if (dist[x*N + y-1] > t + 1) {
                    dist[x*N + y-1] = t + 1;
                    pq.push(CoordDistTime{t1, x, y-1});
                }
            }
        }

        return -1;
    }
};

static const auto k = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();