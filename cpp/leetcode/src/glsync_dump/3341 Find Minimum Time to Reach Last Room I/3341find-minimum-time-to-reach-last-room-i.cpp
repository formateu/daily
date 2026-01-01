struct State {
    int dist;
    int x;
    int y;

    bool operator<(State const& other) const {
        return dist > other.dist;  
    }
};

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        const int N = moveTime.size();
        const int M = moveTime[0].size();
        std::vector<int> dist(N*M, std::numeric_limits<int>::max());
        std::priority_queue<State> pq;
        
        pq.push({0, 0, 0});
        dist[0] = 0;

        while (!pq.empty()) {
            const auto [_,x,y] = pq.top();
            pq.pop();

            int weight = dist[x*M + y] + 1;

            if (x+1 < N) {
                processNeighbour(moveTime, dist, pq, x+1, y, weight);
            }

            if (x-1 >= 0) {
                processNeighbour(moveTime, dist, pq, x-1, y, weight);
            }

            if (y-1 >= 0) {
                processNeighbour(moveTime, dist, pq, x, y-1, weight);
            }

            if (y+1 < M) {
                processNeighbour(moveTime, dist, pq, x, y+1, weight);
            }
        }

        return dist.back();
    }

    static inline void processNeighbour(
        const vector<vector<int>> &moveTime,
        std::vector<int> &dist,
        std::priority_queue<State> &pq,
        int x,
        int y,
        int weight) {
        if (weight < moveTime[x][y]+1) {
            weight = moveTime[x][y]+1;
        }

        if (dist[x*moveTime[0].size() + y] > weight) {
            dist[x*moveTime[0].size() + y] = weight;
            pq.push({dist[x*moveTime[0].size() + y], x, y});
        }
    }
};