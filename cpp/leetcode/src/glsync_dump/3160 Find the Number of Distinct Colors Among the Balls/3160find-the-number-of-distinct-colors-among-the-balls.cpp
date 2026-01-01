class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        std::unordered_map<int, int> colorFreqMap(queries.size());
        std::unordered_map<int, int> map(queries.size());

        std::vector<int> result(queries.size());
        for (int i = 0; i < queries.size(); ++i) {
            const auto& number = queries[i][0];
            const auto& color = queries[i][1];

            if (map.contains(number)) {
                if (colorFreqMap[map[number]] == 1) {
                    colorFreqMap.erase(map[number]);
                } else {
                    --colorFreqMap[map[number]];
                }
            }

            map[number] = color;
            if (colorFreqMap.contains(color)) {
                ++colorFreqMap[color];
            } else {
                colorFreqMap.emplace(color, 1);
            }

            result[i] = colorFreqMap.size();
        }

        return result;
    }
};