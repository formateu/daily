class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        std::unordered_set<int> repeats;
        int center = 0;
        for (const auto &edge: edges) {
            const auto &u = edge[0];
            const auto &v = edge[1];

            if (repeats.contains(u)) {
                center = u;
                break;
            } else {
                repeats.emplace(u);
            }

            if (repeats.contains(v)) {
                center = v;
                break;
            } else {
                repeats.emplace(v);
            }
        }

        return center;
    }
};