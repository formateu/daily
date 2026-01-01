class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        std::sort(events.begin(), events.end(), [](const auto &e1, const auto &e2) {
            if (e1.back() != e2.back()) {
                return e1.back() < e2.back();
            }
            return e1.front() < e2.front();
        });
        int max = events.back().back();
        std::vector<int> parent(max + 2);
        std::iota(parent.begin(), parent.end(), 0);
        int result = 0;
        for (const auto &e: events) {
            const int begin = e.front();
            const int end = e.back();
            int d = find(parent, begin);
            if (d <= end) {
                ++result;
                parent[d] = find(parent, d+1);
            }
        }

        return result;
    }

    int find(std::vector<int> &parent, int x) {
        if (parent[x] != x) {
            parent[x] = find(parent, parent[x]);
        }

        return parent[x];
    }
};