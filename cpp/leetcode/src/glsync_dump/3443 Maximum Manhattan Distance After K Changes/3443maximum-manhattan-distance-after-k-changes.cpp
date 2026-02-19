class Solution {
public:
    int maxDistance(string s, int k) {
        int dist = 0, cnt_bad = 0, result = 0, x = 0, y = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == 'N') {
                ++y;
            } else if (s[i] == 'S') {
                --y;
            } else if (s[i] == 'W') {
                --x;
            } else if (s[i] == 'E') {
                ++x;
            }

            int new_dist = std::abs(x) + std::abs(y);
            if (new_dist < dist) {
                ++cnt_bad;
            }
            dist = new_dist;
            result = std::max(result, dist + 2*std::min(cnt_bad, k));
        }

        return result;
    }
};